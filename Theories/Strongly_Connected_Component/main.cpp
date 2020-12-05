void visit(int u) {
   counter++;
   low[u] = counter;
   num[u] = counter;
   stack.push_back(u); 
   for (int j = 0; j < edge[u].size(); j++) {
       int v = edge[u][j];
       if (d[v] != 0) continue;
       if (num[v] == 0) {
           visit(v);
           low[u] = min(low[u], low[v]);
       } else {
           low[u] = min(low[u], numv[v]);
       }
   }
   int v;
   if (low[u] == num[u]) {
       comp++;
       do {
           v = stack.top();
           stack.pop();
           d[v] = comp;
       } while (u != v);
       fr[comp] = true;
   }
}