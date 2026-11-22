struct Node {
    long val;
    Node * prev;
    Node * next;
    Node(long v) : val(v), prev(nullptr), next(nullptr) {}
};

class Solution {
private:
    string final_str = "";

private:
    long get_number(const string& s, int start, int end) {
        long sum = 0;
        for (int i=start; i<end; i++) {
            sum = sum * 10 + s[i] - '0';
        }
        return sum;
    }

    void print_chain(Node * head) {
        head = head->next;
        while(head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    void scan_chain_for_multi_div(Node * head) {
        Node * curr = head->next;
        while (curr) {
            if (curr->val == -3 || curr->val == -4) {  // * 
                Node * p = nullptr;
                if (curr->val == -3) p = new Node(curr->prev->val * curr->next->val);
                else p = new Node(curr->prev->val / curr->next->val);

                curr->prev->prev->next = p;
                p->prev = curr->prev->prev;
                if (curr->next->next) {
                    p->next = curr->next->next;
                    curr->next->next->prev = p;
                }
                delete curr->prev;
                delete curr->next;
                delete curr;
                curr = p->next;
            }
            else {
                curr = curr->next;
            }
        }
    }

    int scan_chain_for_add_sub(Node * head) {
        Node * curr = head->next;
        int res = curr->val;
        while (curr) {
            if (curr->val == -1) {
                res = res + curr->next->val;
            }
            else if (curr->val == -2) {
                res = res - curr->next->val;
            }
            curr = curr->next;
        }
        return res;
    }
public:
    int calculate(string s) {
        vector<pair<int, char>> vec;
        unordered_map<char, int> sign_map = {
            {'+', -1}, {'-', -2}, {'*', -3}, {'/', -4}
        };
        Node * head = new Node(-100);
        Node * curr = head;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == ' ') continue;
            final_str.push_back(s[i]);
        }

        for (int i=0; i<final_str.size(); i++) {
            char ch = final_str[i];
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                vec.push_back(make_pair(i, ch));
            }
        }

        // cout << final_str << endl;
        int begin = 0;
        for (int i=0; i<vec.size(); i++) {
            int sign_pos = vec[i].first;
            char sign_ch = vec[i].second;
            int number = get_number(final_str, begin, sign_pos);
            begin = sign_pos + 1;
            Node * p1 = new Node(number);
            curr->next = p1;
            p1->prev = curr;
            curr = p1;
            Node * p2 = new Node(sign_map[sign_ch]);
            curr->next = p2;
            p2->prev = curr;
            curr = p2;
        }
        int last_number = get_number(final_str, begin, final_str.size());
        Node * p = new Node(last_number);
        curr->next = p;
        p->prev = curr;
        curr = p;

        //print_chain(head);
        scan_chain_for_multi_div(head);
        //print_chain(head);
        return scan_chain_for_add_sub(head);
    }
};
