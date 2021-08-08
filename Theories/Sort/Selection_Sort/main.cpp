For (int I = 0; I < n - 1; i++) {
	Min_idx = I;
	For (int j = I + 1; j < n ; j++) {
		If (arr[j] < arr[min_idx]) min_idx = j;
	}
	Swap(arr[min_idx], arr[i]);
}

