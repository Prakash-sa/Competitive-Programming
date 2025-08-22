//https://leetcode.com/problems/design-a-text-editor/


class TextEditor {
    string before,after;
public:
    TextEditor() {
    }
    
    void addText(string text) {
        before+=text;
    }
    
    int deleteText(int k) {
        k=min(k,(int)before.size());
        before.resize(before.size()-k);
        return k;
    }
    
    string cursorLeft(int k) {
        while(k-- && !before.empty()){
            after.push_back(before.back());
            before.pop_back();
        }
        int len=min(10,(int)before.size());
        return before.substr(before.size()-len);
    }
    
    string cursorRight(int k) {
        k=min(k,(int)after.size());
        while(k-- && !after.empty()){
            before.push_back(after.back());
            after.pop_back();
        }
        int len=min(10,(int)before.size());
        return before.substr(before.size()-len);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */