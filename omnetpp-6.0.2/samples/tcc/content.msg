message ContentMsg
{
    int source_num;
    char type;
    int destination;
    int hopCount = 0;
    char content;
    int chunk;
    int tcp_type;
}