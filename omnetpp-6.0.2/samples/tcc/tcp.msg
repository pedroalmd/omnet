message TcpMsg
{
    int source_num;
    int destination;
    char content = 't';
	int syn_ack;
	int token;
}