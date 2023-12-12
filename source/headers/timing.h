struct timeval tstart, tend, pstart, pend;

float net_time(struct timeval start, struct timeval end) {
    return end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)/1.e6;
}

bool is_runtime_complete(void){
    return net_time(pstart, pend) >= 60;
}