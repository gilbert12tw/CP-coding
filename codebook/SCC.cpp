int low[mxN], dfn[mxN], dtm;
bitset<mxN> inst;

void tarjan(int u) {
    low[u] = dfn[u] = ++dtm;
    st.pb(u); inst[u] = 1;
    for(int v : g[u]) {
        if(inst[v]) low[u] = min(low[u], dfn[v]);
        if(dfn[v]) continue;
        tarjan(v);
        low[u] = min(low[u], low[v]);
    }
    if(dfn[u] == low[u]) {
        int x;
        do {
            x = st.back(); st.pop_back();
            scc[cnt].pb(x);
            id[x] = cnt;
            inst[x] = 0;
        } while(x != u);
         cnt++;
    }
}
