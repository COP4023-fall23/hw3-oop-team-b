struct  Client
{ 
    private:
        //define your private members here
        string client_name;
        string ssn;
        double bank_account;
        double balance;
    
    public:
        //define your public members here
    void set_client_info(string );
    void get_client_info();
    double deposit(double account_number, double amount);
    string withdraw(double account_number, double amount);
    void saving_info(string file_name);
    void find_client(double account_number)
    Client(){}; //constructor
    Client(string file_name);
    ~Client();
};

Class Bank::public Client
{
    private:
    int num_client;
    Client **client_info;
};
