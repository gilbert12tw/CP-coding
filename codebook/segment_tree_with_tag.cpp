#define ls x<<1
#define rs x<<1|1
#define mid (l+r>>1)

void up(int x) {
	seg[x] = seg[ls] + seg[rs];
}

void build(int l = 1, int r = n, int x = 1) {
	if(l == r) {
		seg[x] = a[l];
		return;
	}
	build(l, mid, ls);	build(mid+1, r, rs);
	up(x);
}

void down(int l, int r, int x) {
	if(!tag[x]) return;
	seg[ls] += tag[x] * (mid - l + 1);
	seg[rs] += tag[x] * (r - mid);
	tag[ls] += tag[x];
	tag[rs] += tag[x];
	tag[x] = 0;
}

void modify(int a, int b, int v, int l = 1, int r = n, int x = 1) {
	if (l != r) down(l, r, x);
	if(a <= l and r <= b) {
		seg[x] += v * (r - l + 1);
		tag[x] += v;
		down(l, r, x);
		return;
	}
	if(a <= mid) modify(a, b, v, l, mid, ls);
	if(b > mid) modify(a, b, v, mid+1, r, rs);
	up(x);
}

int query(int a, int b, int l = 1, int r = n, int x = 1) {
	down(l, r, x);
	if(a <= l and r <= b) return seg[x];
	int res = 0;
	if(a <= mid) res = query(a, b, l, mid, ls);
	if(b > mid) res += query(a, b, mid+1, r, rs);
	return res;
}
