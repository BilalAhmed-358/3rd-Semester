#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class graph
{
    int **table;
    int s;

public:
    graph(int no)
    {
        s = no;
        table = new int *[s + 1];
        for (int i = 0; i <= s; i++)
        {
            table[i] = new int[s + 1];
        }
        for (int i = 0; i <= s; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                table[i][j] = 0;
            }
        }
    }
    void add_edge(int a, int b)
    {
        if (a > s || b > s)
            return;
        table[a][b] = 1;
        table[b][a] = 1;
    }
    void display()
    {
        int z = 0;
        for (int i = 0; i <= s; i++)
        {
            cout << z++ << "\t";
            for (int j = 0; j <= s; j++)
            {
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
    }
    bool check(int a, int b)
    {
        if (a > s || b > s)
            return false;
        if (table[a][b] == 1 || table[b][a] == 1)
            return true;
        else
            return false;
    }
    int total_edges()
    {
        int l = 0;
        for (int i = 0; i <= s; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (table[i][j] == 1)
                    l++;
            }
        }
        return l / 2;
    }
    bool if_alone_or_if_no_connection()
    {
        int l = 0;
        for (int i = 0; i <= s; i++)
        {
            l = 0;
            for (int j = 0; j <= s; j++)
            {
                l++;
            }
            if (l == s + 1)
                return true;
        }
        return false;
    }
    bool isloop()
    {
        for (int i = 0; i <= s; i++)
        {
            if (table[i][i] == 1)
                return false;
        }
        return true;
    }
    void bfs()
    {

        struct vertex
        {
            int a, b;
        };
        queue<vertex *> que;
        vertex *temp, *temp1;
        int i, j;
        int visited[s + 1] = {0};
        visited[1] = 1;
        cout << 1;
        for (j = 1; j <= s; j++)
        {
            if (table[1][j] == 1)
            {
                temp = new vertex;
                temp->a = 1;
                temp->b = j;
                que.push(temp);
                visited[j] = 1;
            }
        }
        int zzzz = 0;
        while (!que.empty())
        {
            temp = que.front();
            que.pop();
            cout << temp->b;
            zzzz = temp->b;
            for (int i = 1; i <= s; i++)
            {
                if (table[zzzz][i] == 1)
                {
                    temp = new vertex;
                    temp->a = zzzz;
                    temp->b = i;
                    if (visited[i] != 1)
                    {
                        visited[i] = 1;
                        que.push(temp);
                    }
                }
            }
        }
    }
};

using namespace std;

int main()
{
    graph obj(4);
    obj.add_edge(1, 3);
    obj.add_edge(3, 2);
    obj.add_edge(2, 4);

    //   graph obj(7);
    //   obj.add_edge(1,7);
    //   obj.add_edge(1,6);
    //   obj.add_edge(1,2);
    //   obj.add_edge(2,7);
    //   obj.add_edge(2,1);
    //   obj.add_edge(3,4);
    //   obj.add_edge(3,5);
    //   obj.add_edge(3,7);
    //   obj.add_edge(4,6);
    //   obj.add_edge(4,7);
    //   obj.add_edge(4,3);
    //   obj.add_edge(5,3);
    //   obj.add_edge(5,7);
    //   obj.add_edge(6,7);
    //   obj.add_edge(6,4);
    //   obj.add_edge(6,1);
    obj.display();
    cout << obj.total_edges() << " " << obj.if_alone_or_if_no_connection();
    cout << "bfs\n";
    obj.bfs();
    return 0;
}