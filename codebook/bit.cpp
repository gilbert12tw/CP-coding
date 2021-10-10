struct BIT{
	int b[mxN];
	int qry(int i) {
		int res = 0;
		for (; i > 0; i -= (i&-i)) res += b[i];
		return res;
	}
	void upd(int i, int v) {
		for (; i < mxN; i += (i&-i)) b[i] += v; 
	}
	int findk(int k) {
		int id = 0;
		int mx = __lg(n) + 1;
		for (int i = mx; i >= 0; i--) {
			if ((id | (1<<i)) > n) continue;
			if (b[id|(1<<i)] < k) id = (id | (1<<i));
		}
		return id + 1;
	}
};
