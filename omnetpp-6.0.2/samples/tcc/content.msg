message ContentMsg
{
    int source_num;
    char type;
    int destination;
    int hopCount = 0;
    char content;
    int chunk;
    int tcp_type;
    omnetpp::simtime_t c_average_chunk_arr;
    omnetpp::simtime_t c_finish_dwnl_time;
	omnetpp::simtime_t c_total_stall_time;
	int c_stall_count_size;
}