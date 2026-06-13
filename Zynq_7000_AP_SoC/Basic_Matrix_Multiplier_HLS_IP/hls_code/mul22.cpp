void mul22(int a11 , int a12 , int a21 , int a22 , int b11 , int b12 , int b21 , int b22 , int &c11 , int &c12 , int &c21 , int &c22)
{
#pragma HLS INTERFACE mode=s_axilite bundle=control port=a11
#pragma HLS INTERFACE mode=s_axilite bundle=control port=a12
#pragma HLS INTERFACE mode=s_axilite bundle=control port=a21
#pragma HLS INTERFACE mode=s_axilite bundle=control port=a22
#pragma HLS INTERFACE mode=s_axilite bundle=control port=b11
#pragma HLS INTERFACE mode=s_axilite bundle=control port=b12
#pragma HLS INTERFACE mode=s_axilite bundle=control port=b21
#pragma HLS INTERFACE mode=s_axilite bundle=control port=b22
#pragma HLS INTERFACE mode=s_axilite bundle=control port=c11
#pragma HLS INTERFACE mode=s_axilite bundle=control port=c12
#pragma HLS INTERFACE mode=s_axilite bundle=control port=c21
#pragma HLS INTERFACE mode=s_axilite bundle=control port=c22

#pragma HLS INTERFACE mode=s_axilite bundle=control port=return
	c11 = (a11*b11) + (a12*b21);
	c12 = (a11*b12) + (a12*b22);
	c21 = (a21*b11) + (a22*b21);
	c22 = (a21*b12) + (a22*b22);
}
