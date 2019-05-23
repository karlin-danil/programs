#include <iostream>

#ifndef MYQUEUE_H
#define MYQUEUE_H
#endif // MYQUEUE_H
#include <vector>
#include <string>
using namespace std;

template <class T>

class MyQueue
{
public:

	MyQueue()
		: m_size(0)
		, m_front_index(-1)
		, m_back_index(-1)
	{}

	bool empty()
	{
		return (0 == m_size);
	}

	size_t size()
	{
		return m_size;
	}

	void print()
	{
		cout << "Content of queue from front to back: ";
		if (empty())
		{
			cout << "Queue is empty" << endl;
		}
		else
		{
			for (auto i = m_front_index; i < m_front_index + m_size; ++i)
			{
				cout << m_vec[i] << " ";
			}
			cout << endl;
		}
	}

	T front()
	{
		if (empty())
		{
			// проверяем на пустоту, так как не имеем право обращаться к первому элементу при пустой очереди
			throw - 1;
		}


		return m_vec[m_front_index];
	}

	T back()
	{
		if (empty())
		{
			// проверяем на пустоту, так как не имеем право обращаться к последнему элементу при пустой очереди
			throw - 1;
		}


		return m_vec[m_back_index];
	}

	void push(const T& item)
	{
		if (empty())
		{

			m_vec.push_back(item);
			++m_front_index;
			++m_back_index;
			++m_size;
			return;
		}
		// в противном случае если очередь не пустая
		m_vec.push_back(item);
		++m_back_index;
		++m_size;
	}

	T pop()
	{
		if (empty())
		{
			// проверяем на пустоту, нельзя снимать из пустой очереди
			throw - 1;
		}

		// если с пустотой проблем нет
		--m_size;
		auto deleted_item = m_vec[m_front_index];
		++m_front_index;



		if (empty())
		{

			m_vec.clear();
			m_back_index = -1;
			m_front_index = -1;
		}

		return deleted_item;
	}

private:

	vector<T> m_vec;
	size_t m_size;
	int m_front_index;
	int m_back_index;
};


int main()
{
	auto exit_flag = false;

	MyQueue<int> myqueue;
	while (!exit_flag)
	{
		cout << "1. Push element to queue" << endl;
		cout << "2. Pop element from queue" << endl;
		cout << "3. Size of queue" << endl;
		cout << "4. Print all elements of queue" << endl;
		cout << "5. Print front of queue" << endl;
		cout << "6. Print back of queue" << endl;
		cout << "7. Exit" << endl;
		cout << endl;
		int menu_number;
		cout << "Select option from menu: ";
		cin >> menu_number;

		switch (menu_number)
		{
		case 1:
		{
			cout << endl;
			int push_item;
			cout << "Please enter item for push: ";
			cin >> push_item;
			myqueue.push(push_item);
		}
		break;
		case 2:
		{
			try
			{
				auto popped_item = myqueue.pop();
				cout << "Pop 1 item from queue with value: " << popped_item << endl;
			}
			catch (int a)
			{
				cerr << "Queue is empty. No items for pop" << endl;
			}

		}
		break;
		case 3:
			cout << "Size of queue = " << myqueue.size() << endl;
			break;
		case 4:
			myqueue.print();
			break;
		case 5:
		{
			try
			{
				cout << "Front item of queue: " << myqueue.front() << endl;
			}
			catch (int a)
			{
				cerr << "Queue is empty. Front item not exist" << endl;
			}
		}
		break;
		case 6:
		{
			try
			{
				cout << "Back item of queue: " << myqueue.back() << endl;
			}
			catch (int a)
			{
				cerr << "Queue is empty. Back item not exist" << endl;
			}
		}
		break;
		case 7:
			exit_flag = true;
			break;
		default:
			cout << "Wrong menu" << endl;
			break;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

