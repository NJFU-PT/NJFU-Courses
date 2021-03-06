#include"TextEditer.h"

TextEditer::TextEditer(){
    is = nullptr;
    os = nullptr;
}

TextEditer::~TextEditer(){
    is->close();
    is->clear();
    delete is;
}

void TextEditer::List(std::string &sub){
    int begin;
    int end;
    char del;
    ss >> begin >> del >> end;
    for (int i = begin - 1; i <= end - 1;i++){
        std::cout << i+1 << " : "<<buffer.at(i) << std::endl;
    }
} 

void TextEditer::Insert(std::string &sub,int m){
    std::string s;
    std::vector<std::string> tmp;
    m--;
    while(ss >> s){
        tmp.push_back(s);
    }
    buffer.insert(buffer.begin()+m, tmp.begin(),tmp.end());
}

void TextEditer::Delete(int begin,int end){
    buffer.erase(buffer.begin() + begin - 1, buffer.begin() + end );
}

void TextEditer::in(){
    if(is = new std::ifstream("TextEditer.cpp")){
        std::string s;
        while(!is->eof()){
            std::getline(*is, s);
            text.push_back(s);
        }
        buffer = text;
    }else{
        std::cerr << "open file error" << std::endl;
        exit(0);
    }
}

void TextEditer::mainProcess(){
    std::string s;

    while(std::getline(std::cin,s)){
        // std::cout << s;
        auto i = std::find(s.begin(), s.end(), '*');
        if(i!=s.end()){
            //find
            char cmd = *++i;
            char del;
            if(cmd!='L'&&cmd!='I'&&cmd!='D'&&cmd!='X'&&cmd!='Q'&&cmd!='R'){
                std::cerr << "wrong cmd" << std::endl;
                exit(0);
            }
            if (cmd == 'X')
            {
                text = buffer;
                out();
                break;
            }
            else if (cmd == 'Q')
            {
                break;
            }else{
                
                i+=2;
                std::string sub(i, s.end());

                ss << sub;

                if(cmd=='L'){
                    List(sub);
                }else if (cmd == 'I'){
                    int m;
                    ss >> m;
                    // ss >> del;
                    Insert(sub, m);
                }

                else if (cmd == 'D')
                {
                    int begin, end;
                    ss >> begin >> del >> end;
                    Delete(begin, end);
                }
                else if (cmd == 'R')
                {
                    int begin, end;
                    char del;
                    ss >> begin >> del >> end;
                    Delete(begin, end);
                    Insert(sub, begin);
                }
            }
            ss.clear();
        }
    }
}

void TextEditer::out(){
    os = new std::ofstream("result/text.txt");
    for(auto i:text){
        *os << i << std::endl;
    }
}