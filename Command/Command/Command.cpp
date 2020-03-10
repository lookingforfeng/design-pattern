#include <iostream>
using namespace std;

class Command
{
public:
    Command() {};
    virtual void execute() {};
};

class Commander
{
public:
    Commander(Command* cmd) 
    {
        this->m_cmd = cmd;        
    };

    void run_the_cmd()
    {
        cout << "send the order ing" << endl;
        m_cmd->execute();
    }

    void registe_cmd(Command* cmd)
    {
        this->m_cmd = cmd;
    }

private:
    Command* m_cmd;
};

class work_cmd:public Command
{
public:
    void execute()
    {
        cout << "work command is running" << endl << endl;;
    }
};

class study_cmd :public Command
{
public:
    void execute()
    {
        cout << "study command is running" << endl << endl;;
    }
};


int main()
{
    Command* cmd1 = new work_cmd();
    Commander* order = new Commander(cmd1);
    order->run_the_cmd();

    cmd1 = new study_cmd();
    order->registe_cmd(cmd1);
    order->run_the_cmd();
}

