class MinStack {
public:

    stack<long long> st;
    long long mini;
    MinStack() {
         mini = INT_MAX;
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            mini = value;
        }
        else{
            if(value < mini){
                st.push(2LL*value-mini);
                mini = value;
            }
            else st.push(value);
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long el = st.top();
        st.pop();
        if(el < mini ){
            mini = 2LL*mini - el;
        }

    }
    
    int top() {
        if(st.empty()) return -1;
        long long el = st.top();
        return (el<mini) ? mini : el;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */