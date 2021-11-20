#include"AutoMata"
int main()
{
    DFA Evr;
    Evr.CreateState("A",DFA::STATE_TYPE::STATE_TYPE_INITIAL_AND_FINAL);
    Evr.CreateState("B",DFA::STATE_TYPE::STATE_TYPE_NORMAL);
    Evr.CreateState("C",DFA::STATE_TYPE::STATE_TYPE_NORMAL);
    Evr.CreateState("D",DFA::STATE_TYPE::STATE_TYPE_NORMAL);
    
    Evr.BindState("A","B",'a');
    Evr.BindState("B","C",'b');
    Evr.BindState("B","D",'a');
    Evr.BindState("C","A",'a');
    Evr.BindState("C","D",'b');
    Evr.BindState("A","D",'b');

    std::string inp;
    DFA::_Out obj;
    while(true)
    {
        std::cin>>inp;
        obj = Evr.run(inp);
        for(auto x:obj.first)
        {
            std::cout<<x<<"->";
        }
        std::cout<<std::boolalpha<<obj.second<<std::endl;
    }
    return 0;
}