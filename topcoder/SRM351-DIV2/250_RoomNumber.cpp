class RoomNumber{
public:
	int numberOfSets(int roomNumber){
		int digit[10] = {0};
		while(roomNumber){
			digit[roomNumber % 10]++;
			roomNumber /= 10;
		}
		digit[6] = (digit[6] + digit[9] + 1) / 2;
		
		int ret = digit[0];
		for(int i = 1; i < 9; i++){
			if(digit[i] > ret) ret = digit[i];
		}			
		return ret;
	};
};