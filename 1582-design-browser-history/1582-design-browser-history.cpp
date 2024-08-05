class BrowserHistory {
public:
    stack<string> current;
    stack<string> next;
    string homepage;
    BrowserHistory(string homepage) {
        this->homepage=homepage;
    }
    
    void visit(string url) {
        // while(forward.size()){
        //     forward.pop();
        // }
        stack<string> temp;
        next=temp;
        current.push(url);
    }
    
    string back(int steps) {
        int size = current.size();
        if(size<=steps){
            steps=size;
        }
        for(int i=0;i<steps;i++){
            string temp=current.top();
            current.pop();
            next.push(temp);
        }
        if(steps==size){
            return homepage;
        }
        return current.size()!=0 ? current.top() : homepage;
        //return homepage;
    }
    
    string forward(int steps) {
        int size = next.size();
        if(size<=steps){
            steps=size;
        }
        for(int i=0;i<steps;i++){
            string temp=next.top();
            next.pop();
            current.push(temp);
        }
        if(current.size()){
            return current.top();
        }
        return homepage;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */