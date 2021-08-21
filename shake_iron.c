#include <stdio.h>
#include <stdint.h>

int shark_iron(uint16_t *ptr, uint8_t count)
{

	printf("count: %d\n", count);
//    int ii = 0;
    printf("size of %ld\n", sizeof(ptr));
//    for (ii=0; ii<count; ii++) {
//        printf("ptr[%d] = %u\n", ii, *(ptr+ii));
//    }

	printf("I'm in shark_iron()\n");

	if (count >= 7) {
		uint8_t i;
		for (i = 0; i < count; i++) {
			if (i < 3) {
				//printf("[%d] lt 3\n", i);
				int k = 0;
				//printf("[%d]\n", i);

				uint8_t in_range_flag = 0;

				for (k = 0; k <= i+3; k++) {
				//	if (k == i) {
				//		printf("{%d} ", k);
				//	} else {
				//		printf("%d ", k);
				//	}
					if (k != i) {
						if (*(ptr+k)+15 > 359) {
							//[*(ptr+k)-15,359], [0, *(ptr+k)+15-360]
							if ((*(ptr+i) <= 359 && *(ptr+i) >= *(ptr+k)-15) || (*(ptr+i) <= *(ptr+k)+15-360 && *(ptr+i) >= 0)) {
//								printf("(%d) In %d\n", *(ptr+i), *(ptr+k));
								in_range_flag = 1;
								break;
							} else {
//								printf("(%d) Out %d\n", *(ptr+i), *(ptr+k));
							}
						} else if(*(ptr+k)-15 < 0) {
							//[*(ptr+k)-15+360, 359], [0, *(ptr+k)+15]
							if ((*(ptr+i) <= 359 && *(ptr+i) >= *(ptr+k)-15+360) || (*(ptr+i) <= *(ptr+k)+15 && *(ptr+i) >= 0)) {
//								printf("(%d) In %d\n", *(ptr+i), *(ptr+k));
								in_range_flag = 1;
								break;
							} else {
//								printf("(%d) Out %d\n", *(ptr+i), *(ptr+k));
							}
						} else {
							//[*(ptr+k)-15, *(ptr+k)+15]
							if (*(ptr+i) <= *(ptr+k)+15 && *(ptr+i) >= *(ptr+k)-15) {
//								printf("(%d) In %d\n", *(ptr+i), *(ptr+k));
								in_range_flag = 1;
								break;
							} else {
//								printf("(%d) Out %d\n", *(ptr+i), *(ptr+k));
							}
						}
					} else {
//						printf("i == k, so do nothing!\n");
					}
				}
				if (in_range_flag == 0) {
//					printf("None!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
					if (i == 0)
						*(ptr+i) = *(ptr+i+1);
					else
						*(ptr+i) = *(ptr+i-1);
				}
//				printf("\n");
			} else if (i >= 3 && i <= count-1-3) {
				//printf("[%d] ge 3 and le %d-1-3\n", i, count);
				int k = 0;
				//printf("[%d]\n", i);	

				uint8_t in_range_flag = 0;

				for (k = i-3; k <= i+3; k++) {
				//	if (k == i) {
				//		printf("{%d} ", k);
				//	} else {
				//		printf("%d ", k);
				//	}
					if (k != i) {
					//	if (*(ptr+k)-15 < *(ptr+i) && *(ptr+i) < *(ptr+k)+15) {
					//		break;
					//	}
						//printf("(%d)\n", *(ptr+i));
						if (*(ptr+k)+15 > 359) {
							//[*(ptr+k)-15,359],      [0, *(ptr+k)+15-360]
							if ((*(ptr+i) <= 359 && *(ptr+i) >= *(ptr+k)-15) || (*(ptr+i) <= *(ptr+k)+15-360 && *(ptr+i) >= 0)) {
//								printf("(%d) In %d\n", *(ptr+i), *(ptr+k));
								in_range_flag = 1;
								break;
							} else {
//								printf("(%d) Out %d\n", *(ptr+i), *(ptr+k));
							}
						} else if(*(ptr+k)-15 < 0) {
							//[*(ptr+k)-15+360, 359], [0, *(ptr+k)+15]
							if ((*(ptr+i) <= 359 && *(ptr+i) >= *(ptr+k)-15+360) || (*(ptr+i) <= *(ptr+k)+15 && *(ptr+i) >= 0)) {
//								printf("(%d) In %d\n", *(ptr+i), *(ptr+k));
								in_range_flag = 1;
								break;
							} else {
//								printf("(%d) Out %d\n", *(ptr+i), *(ptr+k));
							}
						} else {
							//[*(ptr+k)-15, *(ptr+k)+15]
							if (*(ptr+i) <= *(ptr+k)+15 && *(ptr+i) >= *(ptr+k)-15) {
//								printf("(%d) In %d\n", *(ptr+i), *(ptr+k));
								in_range_flag = 1;
								break;
							} else {
//								printf("(%d) Out %d\n", *(ptr+i), *(ptr+k));
							}
						}
					} else {
//						printf("i == k, so do nothing!\n");
					}
				}
				if (in_range_flag == 0) {
//					printf("None!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
					*(ptr+i) = *(ptr+i-1);
				}
//				printf("\n");
			
			} else if (i > count-1-3) {
				//printf("[%d] gt %d-1-3\n", i, count);
				int k = 0;
				//printf("[%d]\n", i);	

				uint8_t in_range_flag = 0;

				for (k = i-3; k <= count-1; k++) {
				//	if (k == i) {
				//		printf("{%d} ", k);

				//	} else {
				//		printf("%d ", k);
				//	
				//	}
					if (k != i) {
					//	if (*(ptr+k)-15 < *(ptr+i) && *(ptr+i) < *(ptr+k)+15) {
					//		break;
					//	}
						//printf("(%d)\n", *(ptr+i));
						if (*(ptr+k)+15 > 359) {
							//[*(ptr+k)-15,359],      [0, *(ptr+k)+15-360]
							if ((*(ptr+i) <= 359 && *(ptr+i) >= *(ptr+k)-15) || (*(ptr+i) <= *(ptr+k)+15-360 && *(ptr+i) >= 0)) {
//								printf("(%d) In %d\n", *(ptr+i), *(ptr+k));
								in_range_flag = 1;
								break;
							} else {
//								printf("(%d) Out %d\n", *(ptr+i), *(ptr+k));
							}
						} else if(*(ptr+k)-15 < 0) {
							//[*(ptr+k)-15+360, 359], [0, *(ptr+k)+15]
							if ((*(ptr+i) <= 359 && *(ptr+i) >= *(ptr+k)-15+360) || (*(ptr+i) <= *(ptr+k)+15 && *(ptr+i) >= 0)) {
//								printf("(%d) In %d\n", *(ptr+i), *(ptr+k));
								in_range_flag = 1;
								break;
							} else {
//								printf("(%d) Out %d\n", *(ptr+i), *(ptr+k));
							}
						} else {
							//[*(ptr+k)-15, *(ptr+k)+15]
							if (*(ptr+i) <= *(ptr+k)+15 && *(ptr+i) >= *(ptr+k)-15) {
//								printf("(%d) In %d\n", *(ptr+i), *(ptr+k));
								in_range_flag = 1;
								break;
							} else {
//								printf("(%d) Out %d\n", *(ptr+i), *(ptr+k));
							}
						}
					} else {
//						printf("i == k, so do nothing!\n");
					}
				}
				if (in_range_flag == 0) {
//					printf("None!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
					*(ptr+i) = *(ptr+i-1);
				}
//				printf("\n");
			
			} else {
				printf("Impossible!\n");
	
			}
		
		}

	} else {
	
		printf("do nothing.\n");
	
	}


	return 0;
}

