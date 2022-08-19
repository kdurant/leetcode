#include <iostream>
#include <cstring>

class Student
{
private:
    int   m_age;
    char* m_name{nullptr};

public:
    Student() = default;
    Student(int age, char* name) :
        m_age(age)
    {
        std::cout << "Student constructor" << std::endl;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }
    Student(const Student& cpy)
    {
        std::cout << "Student copy constructor" << std::endl;
        m_age  = cpy.m_age;
        m_name = new char[strlen(cpy.m_name) + 1];
        strcpy(m_name, cpy.m_name);
    }
    Student& operator=(const Student& assign)
    {
        std::cout << "Student assignment operator" << std::endl;
        if(this != &assign)
        {
            m_age  = assign.m_age;
            m_name = new char[strlen(assign.m_name) + 1];
            strcpy(m_name, assign.m_name);
        }
        return *this;
    };

    Student(Student&& move)
    {
        std::cout << "Student move constructor" << std::endl;
        m_age       = move.m_age;
        m_name      = move.m_name;
        move.m_name = nullptr;
    }

    Student& operator=(Student&& assign)
    {
        std::cout << "Student move assignment operator" << std::endl;
        if(this != &assign)
        {
            m_age         = assign.m_age;
            m_name        = assign.m_name;
            assign.m_name = nullptr;
        }
        return *this;
    }

    ~Student()
    {
        if(m_name != nullptr)
            delete m_name;
    }
};

int main(void)
{
    Student s1(20, "John");
    Student s2(s1);

    Student s3;
    s3 = s1;  // 对象存在，用别的对想给他赋值
    //
    Student s4(std::move(s1));

    return 0;
}
