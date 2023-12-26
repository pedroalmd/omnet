message ContentMsg
{
    int source_num;
    char source_type;
    int destination;
    int hopCount = 0;
    char content;
    int tcp_type;
}