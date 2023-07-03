#include <iostream>
#include <sstream>


static bool match(std::stringstream& s, const std::string& p) {

    /*
        Mögliche p's:
        - "[a-z]"
        - "[a-z]*"
        - "."
        - ".*"

        -> ein Zeichen "[a-z\.]" und optional ein modifier "*"
    */
    
    if (p.length() > 0) {
        
        char c = s.get();

        if (p.length() == 1)
            return (p[0] == c || p[0] == '.') && c != EOF;

        if (p.length() == 2) { // only if p[1] == '*'
            if (p[0] == '.') {
                if (c == EOF)
                    return false;
                while (c != EOF)
                    c = s.get();
                return true;
            }
            if (c != p[0])
                return false;

            while (c == p[0])
                c = s.get();

            if (c != EOF)
                s.putback(c);
            
            return true;
        }

    } else {
        const char c = s.get();
        if (c == EOF)
            return true;
        else {
            s.putback(c);
            return false;
        }
    }
}

static bool isMatch(const std::string& s, const std::string& p) {
    /*
    sugoma
    */
}

int main() {

    {
        const std::string s = "aa", p = "a";
        std::cout << "s: " << s << ", p: " << p << std::endl;
        std::cout << "isMatch: " << std::to_string(isMatch(s, p)) << std::endl;
    }

    {
        std::string s = "aa", p = "a*";
        std::cout << "s: " << s << ", p: " << p << std::endl;
        std::cout << "isMatch: " << std::to_string(isMatch(s, p)) << std::endl;
    }

    {
        std::string s = "ab", p = ".*";
        std::cout << "s: " << s << ", p: " << p << std::endl;
        std::cout << "isMatch: " << std::to_string(isMatch(s, p)) << std::endl;
    }

    return 0;
}