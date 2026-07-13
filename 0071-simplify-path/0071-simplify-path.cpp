class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        string curr = "";

        for(int i = 0; i <= path.size(); i++){

            if(i == path.size() || path[i] == '/'){

                if(curr == "" || curr == "."){
                    // Ignore
                }
                else if(curr == ".."){

                    if(!st.empty())
                        st.pop();

                }
                else{

                    st.push(curr);

                }

                curr = "";
            }
            else{

                curr += path[i];

            }
        }

        vector<string> folders;

        while(!st.empty()){

            folders.push_back(st.top());
            st.pop();

        }

        reverse(folders.begin(), folders.end());

        string ans = "";

        for(string folder : folders){

            ans += "/";
            ans += folder;

        }

        if(ans == "")
            return "/";

        return ans;
    }
};