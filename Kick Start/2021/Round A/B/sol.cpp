//L Shaped Plots
// Solution: Count valid L shapes of each perpendicular lines intersection
#include <bits/stdc++.h>
using namespace std;

int countLShapes(int a, int b) {
    int c = 0;
    for (int i=2; i<=a; i++) {
        int j = 2*i;
        c += ((i <= a && j <= b) || (i <= b && j <= a));
    }
    return c;
}

int main() {
    // freopen("sample.in", "r", stdin);
    int t;
    cin >> t;
    for (int tc=1; tc<=t; tc++) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> grid(r, vector<int>(c, 0));
        int i, j;
        for (i=0; i<r; i++) {
            for (j=0; j<c; j++) {
                cin >> grid[i][j];
            }
        }
        vector<pair<pair<int, int>, int>> vlines, hlines;
        for (j=0; j<c; j++) {
            int prev_r = -1, ir = -1;
            for (i=0; i<r; i++) {
                if (grid[i][j]) {
                    ir = i;
                } else {
                    if (ir != -1 && prev_r != -1 && abs(ir - prev_r + 1) > 1) {
                        vlines.push_back({{prev_r, ir}, j});
                    }
                    prev_r = -1;
                    ir = -1;
                }
                if (prev_r == -1 && ir != -1) prev_r = ir;
            }
            if (ir != -1 && prev_r != -1 && abs(ir - prev_r + 1) > 1) {
                vlines.push_back({{prev_r, ir}, j});
            } 
        }

        for (i=0; i<r; i++) {
            int prev_c = -1, ic = -1;
            for (j=0; j<c; j++) {
                if (grid[i][j]) {
                    ic = j;
                } else {
                    if (ic != -1 && prev_c != -1 && abs(ic - prev_c + 1) > 1) {
                        hlines.push_back({{prev_c, ic}, i});
                    }
                    prev_c = -1;
                    ic = -1;
                }
                if (prev_c == -1 && c != -1) prev_c = ic;
            }
            if (ic != -1 && prev_c != -1 && abs(ic - prev_c + 1) > 1) {
                hlines.push_back({{prev_c, ic}, i});
            } 
        }

        int ans = 0;
        for (i=0; i<vlines.size(); i++) {
            int vir = vlines[i].first.first;
            int vic = vlines[i].second;
            int vfr = vlines[i].first.second;
            int vfc = vlines[i].second;
            int vsz = vfr - vir + 1;
            for (j=0; j<hlines.size(); j++) {
                int hir = hlines[j].second;
                int hic = hlines[j].first.first;
                int hfr = hlines[j].second;
                int hfc = hlines[j].first.second;
                int hsz = hfc - hic + 1;
                if (vir<=hir && hir<=vfr && hic<=vic && vic<=hfc) {
                    int inr = hir;
                    int inc = vic;
                    ans += countLShapes(vic - hic + 1, hir - vir + 1);
                    ans += countLShapes(vic - hic + 1, vfr - hir + 1);
                    ans += countLShapes(hfc - vic + 1, vfr - hir + 1);
                    ans += countLShapes(hfc - vic + 1, hir - vir + 1);
                }
            }
        }

        cout << "Case #" << tc << ": " << ans << endl;
    }
    
    return 0;
}