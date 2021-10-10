int dsu[mxN], sz[mxN];

void init() {
	for(int i = 1; i <= n; i++) dsu[i] = i, sz[i] = 1;
}

int get(int x) {
	return dsu[x] == x ? x : dsu[x] = get(dsu[x]);
}

void oni(int a, int b) {
	a = get(a), b = get(b);
	if(a == b) return; 
	if(sz[a] > sz[b]) swap(a, b);
	dsu[a] = b;
	sz[b] += sz[a];
}
