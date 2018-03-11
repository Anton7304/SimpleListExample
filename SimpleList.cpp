#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <crtdbg.h>
#include <iostream>

class CVector//базовый класс векторов
{
public:
    CVector()
    {

    }
    virtual float result()//виртуальный вызов дочерних классов (векторов)
    {

    }
};

class CVector1 : public CVector//одномерный графический вектор
{
public:
    float x1 = 0;
    CVector1(float vecX1)
    {
        x1 = vecX1;
    }
    float result()
    {
        float res = fabs(x1);
        return res;
    }
};

class CVector2 : public CVector//двумерный графический вектор
{
public:
    float x1 = 0;
    float x2 = 0;
    CVector2(float vecX1, float vecX2)
    {
        x1 = vecX1;
        x2 = vecX2;
    }
    float result()
    {
        float res = sqrt(x1*x1 + x2*x2);
        return res;
    }
};

template< typename T >
class CVectList//класс списка
{
public:
    CVectList() : m_head( NULL )//конструктор
    {

    }

    ~CVectList()//деструктор
    {
        while( m_head )
        {
            remove();
        }
    }

    void Add( const T& t )//метод добавления элемента в список
    {
        Node* node = new Node(t);
        {
            node->m_next = m_head;
            m_head = node;
        }
    }

    void remove()//удаление элемента из списка
    {
        if( m_head )
        {
            Node* newHead = m_head->m_next;
            delete m_head;
            m_head = newHead;
        }
    }

    size_t PrintLengths() const//вывод длины каждого вектора (в обратном порядке), а также общий размер списка
    {
         size_t s = 0;

         for( Node* n = m_head; n != NULL; n = n->m_next )
         {
             std::cout << "Vector length = " << n->m_t->result() << std::endl;
             ++s;
         }


         std::cout << "List length = " << s << std::endl;
         return s;
    }

private:
    struct Node //структура элемента однонаправленного списка
    {
        Node() : m_next( NULL )
        {

        }
        Node( const T& t ) : m_t( t ), m_next( NULL )
        {

        }
        T m_t;//значение элемента
        Node* m_next;
    };
    Node* m_head;
};

int main(void)
{
    CVector1 a1(3.0);
    CVector2 a2(3.0, 4.0);
    CVector2 a3(-5.0, -12.0);
    CVector1 a4(-15.0);
    CVector2 a5(80.0, -60.0);

    CVectList<CVector *> list;
    list.Add(&a1);
    list.Add(&a2);
    list.Add(&a3);
    list.Add(&a4);
    list.Add(&a5);

    list.PrintLengths();

    _getch();
    return 0;
}
