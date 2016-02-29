class CoinsExchange{
public:
	int countExchanges(int G1, int S1, int B1, int G2, int S2, int B2){
		int ret = 0;
		while(G1 < G2){
			if(S1 >= 11){
				ret += 1;
				G1 += 1;
				S1 -= 11;
			}
			else{
				ret += 1;
				S1 += 1;
				B1 -= 11;
			}
			if(B1 < 0) return -1;
		}
		while(S1 < S2){
			if(G1 > G2){
				ret += 1;
				S1 += 9;
				G1 -= 1;
			}
			else{
				ret += 1;
				S1 += 1;
				B1 -= 11;
			}
			if(B1 < 0) return -1;
		}
		while(B1 < B2){
			if(S1 > S2){
				ret += 1;
				B1 += 9;
				S1 -= 1;
			}
			else{
				ret += 1;
				G1 -= 1;
				S1 += 9;
			}
			if(G1 < G2) return -1;
		}
		return ret;
	};
};