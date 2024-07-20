class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for( auto &i: tokens){
            if( i == "+" || i == "-" || i == "*" || i == "/"){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                if(i == "-"){
                    op1 = op2 - op1;
                }
                if(i == "+"){
                    op1 = op1 + op2;
                }
                if(i == "*"){
                    op1 = op1 * op2;
                }
                if(i == "/"){
                    op1 = op2 / op1;
                }
                st.push(op1);
            }else{
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};