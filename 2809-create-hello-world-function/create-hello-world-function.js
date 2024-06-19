/**
 * @return {Function}
 */
function createHelloWorld() {
    const greeting = "Hello World";
    
    return function(...args) {
        return greeting
        
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */