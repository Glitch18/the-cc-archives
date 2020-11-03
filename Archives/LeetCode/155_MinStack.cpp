//https://leetcode.com/problems/min-stack/

class MinStack {
    stack<int> st;
    stack<int> mins;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if(mins.empty()) mins.push(x);
        else if(x<=mins.top()) mins.push(x);
        st.push(x);
    }

    void pop() {
        if(mins.top()==st.top()) mins.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mins.top();
    }
};

//Not recommended:-
class MinStack {
    multiset<int> sorted;
    stack<int> st;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        st.push(x);
        sorted.insert(x);
    }

    void pop() {
        if(*sorted.begin()==st.top()) sorted.erase(sorted.begin());
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return *sorted.begin();
    }
};
