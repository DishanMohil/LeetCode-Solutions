class Solution {
public:
    int sum(int n,int m){
        return n+m;
    }
    int diff(int n, int m){
        return n-m;
    }
    int pro(int n, int m){
        return n*m;
    }
    int by(int n, int m){
        return n/m;
    }
    int evalRPN(vector<string>& t) {
        stack<int> s;
        for(string str:t){
            try{
                int num = stoi(str);
                s.push(num);
            }
            catch(const invalid_argument& e){
                int num2 = s.top(); s.pop();
                int num1 = s.top(); s.pop();
                if(str == "+") s.push(sum(num1,num2));
                else if(str == "-") s.push(diff(num1,num2));
                else if(str == "*") s.push(pro(num1,num2));
                else s.push(by(num1,num2));
            }
        }
        return s.top();
    }
};