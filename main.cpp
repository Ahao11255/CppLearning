#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/*
    定义一种新类型 Record，里面有两个成员
*/
struct Record
{
    double amount; //金额
    string note; //备注
};

// 从文件中加载记录

/*
    vector<Record>& records：
     引用传参
     直接修改外面的 records

    如果不用 &：
    vector<Record> records
    会变成：

    读到的数据只存在函数内部，main 里看不到
    所以这里必须用：

    & = 传地址 = 改的是同一个容器
*/
void loadFromFIle(vector<Record>& records){

    /*
        创建一个输入文件流对象 fin，并尝试打开 data.txt

        向内存输入    ifstream
        先读金额，再读后面整行备注
    */
    ifstream fin("data.txt");
    
    if (!fin.is_open()) return;
    
    Record r;
    while (fin >> r.amount){
        fin.ignore(); // 忽略金额后的空格
        getline(fin, r.note); // 读取整行备注
        records.push_back(r);
    }

    fin.close();    
}

/*
    const
     保证只读
     编译器禁止你修改它
     只读参数必须加const
*/
// 保存所有记录到文件
void saveToFile(const vector<Record>& records){

    /*
        从内存输出  ofstream
        将内存里的内容写入文件
    */
    ofstream fout("data.txt");
    for(int i=0; i<records.size(); i++){
        fout << records[i].amount << " " << records[i].note << endl;
    }
    fout.close();
}

int main(){

    /*
        定义一个 Record 类型的 vector（动态数组）
        自动扩容
        不用担心内存管理问题
    */
    vector<Record> records; // 用来保存所有记录

    loadFromFIle(records); //启动时加载数据

    int choice = 0;

    while (true)
    {
        /*
            "<<": 把右边的数据 → 送进 cout 管道
            "endl": 输出一个换行符，并刷新输出缓冲区
       */ 

        cout << "1. 添加记录" << endl;
        cout << "2. 查看记录" << endl;
        cout << "3. 删除记录" << endl;
        cout << "4. 修改记录" << endl;
        cout << "5. 退出" << endl;
        cout << "请输入您的选择: ";

        /*
            从键盘读一个整数，并存储在变量 choice 中
            ">>": 从 cin 管道 → 读入数据到 choice 变量
        */
 
        cin >> choice;

        if(choice == 1){

            /*
                按 Record 这种“结构”在内存里创建一个变量，名字叫 r
            */
            Record r;

            cout << "请输入金额（输入为正，支出为负）:";
            cin >> r.amount;
            
            /*
                cin >> 会留下一个 \n 在缓冲区
            */
            cin.ignore();   //清除缓冲区里的换行符
            cout << "请输入备注:";

            /*
                从输入流中读取一整行，可包括空格
                cin >> note 不可读取空格
                getline(cin, r.note) 可以读取空格
            */
            getline(cin, r.note);

            /*
                push_back: 向 vector 末尾添加一个元素
                这里把新创建的 Record r 添加到 records 中
            */
            records.push_back(r);
            saveToFile(records);

            cout << "记录已添加！" << endl;

        }else if (choice ==2){
            cout << "当前共有" << records.size() << "条记录:" << endl;

            for (int i =0; i<records.size();i++){
                cout << i+1 
                    << ". 金额: " << records[i].amount 
                    << ", 备注: " << records[i].note << endl;   
            }
        
        }else if(choice == 3){
            int index;
            cout << "请输入要删除的记录编号: ";
            cin >> index;

            if(index < 1 || index > records.size()){
                cout << "编号无效！" << endl;
            }else{
                /*
                    erase
                    从vector中移除元素，并自动前移后面的元素
                */
                records.erase(records.begin() + index - 1);
                saveToFile(records);
                cout << "记录已被删除。" << endl;
            }

        }else if(choice == 4){
            int index;
            cout << "请要修改的记录编号: ";
            cin >> index;

            if(index < 1 || index > records.size()){
                cout << "编号无效" << endl;
            }else{
                cout << "原金额: " << records[index-1].amount
                    << " 原备注: " << records[index-1].note << endl;

                cout << "请输入金额（输入为正，支出为负）:";
                cin >> records[index-1].amount;
                cin.ignore();

                cout << "请输入备注:";
                getline(cin,records[index-1].note);
                saveToFile(records);
                cout << "记录已被修改。" << endl;
            }

        }else if (choice == 5){
            cout << "退出程序" << endl;
            break;
        }else{
            cout << "无效选择，请重新输入！" << endl;
        }
        
    }
    
    return 0;
}
