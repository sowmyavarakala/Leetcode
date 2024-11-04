from collections import defaultdict, OrderedDict

class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0
        self.min_frequency = 0
        self.key_to_value = {}         # Stores key-value pairs
        self.key_to_frequency = {}      # Stores key-frequency pairs
        self.frequency_to_keys = defaultdict(OrderedDict)  # Maps frequency to OrderedDict of keys

    def _update_frequency(self, key: int):
        # Get the current frequency of the key
        freq = self.key_to_frequency[key]
        
        # Remove the key from the current frequency's OrderedDict
        del self.frequency_to_keys[freq][key]
        if not self.frequency_to_keys[freq]:
            del self.frequency_to_keys[freq]
            # Update min_frequency if necessary
            if self.min_frequency == freq:
                self.min_frequency += 1

        # Increment the frequency
        new_freq = freq + 1
        self.key_to_frequency[key] = new_freq
        # Add the key to the new frequency's OrderedDict
        self.frequency_to_keys[new_freq][key] = self.key_to_value[key]

    def get(self, key: int) -> int:
        if key not in self.key_to_value:
            return -1
        # Update the frequency of the key
        self._update_frequency(key)
        return self.key_to_value[key]

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return

        if key in self.key_to_value:
            # Update the value and frequency of an existing key
            self.key_to_value[key] = value
            self._update_frequency(key)
        else:
            # Check if we need to remove the least frequently used key
            if self.size == self.capacity:
                # Remove the least frequently used key (and the least recently used among them)
                lfu_key, _ = self.frequency_to_keys[self.min_frequency].popitem(last=False)
                del self.key_to_value[lfu_key]
                del self.key_to_frequency[lfu_key]
                self.size -= 1

            # Insert the new key-value pair
            self.key_to_value[key] = value
            self.key_to_frequency[key] = 1
            self.frequency_to_keys[1][key] = value
            self.min_frequency = 1
            self.size += 1
