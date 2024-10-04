#include <iostream>

struct meta_data{
    int _id;
    int _value;
    
    meta_data(int id, int value):_id(id),_value(value){}
};

meta_data f_mdata(meta_data m){
    meta_data m_data(0,0);
    m_data._id = m._id + 1;
    m_data._value = m._value +10;
    
    return m_data;
}

meta_data f2_mdata(const meta_data& m){
    meta_data m_data(0,0);
    m_data._id = m._id + 4;
    m_data._value = m._value +1011;
    
    return m_data;
}

void f3_mdata(meta_data& m){
    m._id = m._id + 3;
    m._value = m._value +101;
}

int main()
{
    std::cout<<"Hello World\n";
    meta_data m(4,34);
    meta_data mdata = f_mdata(m);
    
    std::cout <<"meta data input id : " << m._id << "    meta data input value : " << m._value << std::endl;
    std::cout <<"meta data input id : " << mdata._id << "    meta data input value : " << mdata._value << std::endl;
    
    mdata = f2_mdata(m);
    std::cout <<"\nmeta data input id : " << m._id << "    meta data input value : " << m._value << std::endl;
    std::cout <<"meta data input id : " << mdata._id << "    meta data input value : " << mdata._value << std::endl;
    
    f3_mdata(m);
    std::cout <<"\nmeta data input id : " << m._id << "    meta data input value : " << m._value << std::endl;
     
    return 0;
}
