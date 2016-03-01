class UnsealTheSafe{
public:
	long long countPasswords(int N){
		int next[10][4] = {{7}, {2, 4}, {1, 3, 5}, {2, 6}, {1, 5, 7}, {2, 4, 6, 8}, {3, 5, 9}, {4, 8, 0}, {5, 7, 9}, {6, 8}};
		int can_next[10] = {1, 2, 3, 2, 3, 4, 3, 3, 3, 2};
		long long arr[31][10] = {0};
		for(int i = 0; i <= 9; i++)
			arr[1][i] = 1;
		
		for(int i = 1; i < N; i++){
			for(int j = 0; j <= 9; j++){
				for(int k = 0; k < can_next[j]; k++){
					arr[i + 1][next[j][k]] += arr[i][j];
				}
			}
		}
		
		long long result = 0;
		for(int i = 0; i <= 9; i++)
			result += arr[N][i];
			
		return result;
	};
};