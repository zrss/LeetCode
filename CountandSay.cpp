class Solution {
public:
    string countAndSay(int n) {
        int c = 1;
        string rel = "1";
        
        while (c < n) {
            string tmpStr;
            int i = 0;
            
            while (i < rel.length()) {
                // 扫描数字个数
                int tmpCnt = 1;
                char num = rel[i++];
                while (i < rel.length() && rel[i] == num) {
                    ++tmpCnt;
                    ++i;
                }
                
                // 读数字
                tmpStr += to_string(tmpCnt);
                tmpStr.push_back(num);
            }
            
            rel = tmpStr;
            ++c;
        }
        
        return rel;
    }
};