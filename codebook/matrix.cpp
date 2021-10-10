struct mat : vector<vector<int>> {
	int n;
	mat(int _n): vector<vector<int>>(_n, vector<int>(_n, 0)) { n = _n; }
	friend void init(mat &a) {
		for(int i = 0; i < a.n; i++) a[i][i] = 1;
	}
	friend mat operator * (mat &a, mat &b) {
		mat t(a.n);
		for(int i = 0; i < a.n; i++) 
			for(int k = 0; k < a.n; k++) 
				for(int j = 0; j < a.n; j++) t[i][j] = (t[i][j] + a[i][k] * b[k][j]) % mod;
		return t;
	}
	friend mat operator ^ (mat a, int b) {
		mat res(a.n);
		init(res);
		while (b) {
			if (b&1) res = res * a;
			a = a * a;
			b >>= 1;
		}
		return res;
	}
	friend void print(mat & a) {
		cout << "\n";
		for(int i = 0; i < a.n; i++) for(int j = 0; j < a.n; j++) cout << a[i][j] << " \n"[j == a.n-1];	
		cout << "\n";
	}
};
