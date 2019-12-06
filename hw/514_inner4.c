/** Zach Tucker 
 *  Question 5.14
 */

/** Inner product. Accumulate in temporary  
 *  No loop unrolling.
 */
void inner4(vec_ptr u, vec_ptr v, data_t *dest) {
    
    long i;
    long length = vec_length(u);
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);
    data_t sum = data_t 0;

    for (i = 0; i < length; i++) {
        sum = sum + udata[i] * vdata[i];
    }
    
    *dest = sum;
}

/** Inner product. Accumulate in temporary
 *  With 6x1 loop unrolling.
 */
void inner5(vec_ptr u, vec_ptr v, data_t *dest) {
    
    long i;
    long length = vec_length(u);
    long limit = length - 5;
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);
    data_t sum = data_t 0;

    for (i = 0; i < limit; i+= 6) {
        sum = sum + (udata[i] * vdata[i]) + 
                    (udata[i + 1] * vdata[i + 1]) +
                    (udata[i + 2] * vdata[i + 2]) + 
                    (udata[i + 3] * vdata[i + 3]) +
                    (udata[i + 4] * vdata[i + 4]) + 
                    (udata[i + 5] * vdata[i + 5]);
    }

    for (; i < length; i++) {
        sum = sum + udata[i] * vdata[i];
    }

    *dest = sum;
}

/** Inner product. Accumulate in temporay
 *  With 6x6 loop unrolling.
 */
void inner6(vec_ptr u, vec_ptr v, data_t *dest) {
    
    long i;
    long length = vec_length(u);
    long limit = length - 5;
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);
    data_t acc0 = 0;
    data_t acc1 = 0;
    data_t acc2 = 0;
    data_t acc3 = 0;
    data_t acc4 = 0;
    data_t acc5 = 0;

    for (i = 0; i < limit; i+= 6) {
        acc0 = acc0 + udata[i] + vdata[i];
        acc1 = acc1 + udata[i + 1] + vdata[i + 1];
        acc2 = acc2 + udata[i + 2] + vdata[i + 2];
        acc3 = acc3 + udata[i + 3] + vdata[i + 3];
        acc4 = acc4 + udata[i + 4] + vdata[i + 4];
        acc5 = acc5 + udata[i + 5] + vdata[i + 5];
    }

    for (; i < length; i++) {
        acc0 = acc0 + udata[i] + vdata[i];
    }

    *dest = acc0 + acc1 + acc2 + acc3 + acc4 + acc5;
}

/** Inner product. Accumulate in temporary
 *  With 6x1a loop unrolling.
 */
void inner7(vec_ptr u, vec_ptr v, data_t *dest) {
    
    long i;
    long length = vec_length(u);
    long limit = length - 5;
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);
    data_t sum = data_t 0;

    for (i = 0; i < limit; i+= 6) {
        sum = sum +   ((udata[i] * vdata[i]) + (udata[i + 1] * vdata[i + 1])) +
              ((udata[i + 2] * vdata[i + 2]) + (udata[i + 3] * vdata[i + 3])) +
              ((udata[i + 4] * vdata[i + 4]) + (udata[i + 5] * vdata[i + 5]));
    }

    for (; i < length; i++) {
        sum = sum + udata[i] * vdata[i];
    }

    *dest = sum;
}
