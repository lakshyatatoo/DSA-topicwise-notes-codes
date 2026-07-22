#include <bits/stdc++.h>
using namespace std;
// pllacing stations in equal sectors between present stations
// starting by placing inside the largest gap

// // brute.  tle
// class Solution
// {
// public:
//     double minMaxDist(vector<int> &stations, int K)
//     {
//         int totalStations = stations.size();
//         if (totalStations <= 1)
//             return 0.0;

//         // number of extra stations placed in each interval
//         vector<int> extraStations(totalStations - 1, 0);

//         // place K extra stations one by one
//         for (int placed = 1; placed <= K; placed++)
//         {
//             long double maxSegmentLength = -1;
//             int segmentIndex = -1;

//             // find the interval with the largest current segment
//             for (int i = 0; i < totalStations - 1; i++)
//             {
//                 long double intervalLength = stations[i + 1] - stations[i];
//                 long double currentMaxSegment =
//                     intervalLength / (long double)(extraStations[i] + 1);

//                 if (currentMaxSegment > maxSegmentLength)
//                 {
//                     maxSegmentLength = currentMaxSegment;
//                     segmentIndex = i;
//                 }
//             }

//             // add one station to the interval with max segment
//             extraStations[segmentIndex]++;
//         }

//         // calculate final maximum distance between adjacent stations
//         long double answer = 0;
//         for (int i = 0; i < totalStations - 1; i++)
//         {
//             long double intervalLength = stations[i + 1] - stations[i];
//             long double maxSegment =
//                 intervalLength / (long double)(extraStations[i] + 1);

//             answer = max(answer, maxSegment);
//         }

//         return (double)answer;
//     }
// };

//!!!!___BETTER - PRIORITY QUEUE SOLUTION___!!!!
class Solution
{
public:
    double minMaxDist(vector<int> &stations, int K)
    {
        int n = stations.size();
        if (n <= 1)
            return (double)0;
        vector<int> howmany(n - 1, 0);
        priority_queue<pair<long double, int>> pq;
        for (int i = 0; i < n - 1; i++)
        {
            pq.push({stations[i + 1] - stations[i], i});
        }
        for (int i = 1; i <= K; i++)
        {
            auto tp = pq.top();
            pq.pop();
            int secInd = tp.second;
            howmany[secInd]++;                                                    // storing 1 gs here
            long double iniDiff = stations[secInd + 1] - stations[secInd];        // to fetch the distance original ||| pq may have the sector dist so we cal inidiff everytime.
            long double newseclen = iniDiff / (long double)(howmany[secInd] + 1); //+1 because we added 1 gs
            pq.push({newseclen, secInd});
        }

        return pq.top().first;
    }
};

//!!!!___OPTIMAL - BINARY SEARCH ON ANSWERS___!!!!
class Solution
{
public:
    int nofGSreq(long double maxDist, vector<int> &stations)
    {

        int cnt = 0;
        for (int i = 1; i < stations.size(); i++)
        {
            int noinbw = (stations[i] - stations[i - 1]) / maxDist;
            if (stations[i] - stations[i - 1] == noinbw * maxDist)
                noinbw--;
            cnt += noinbw;
        }
        return cnt;
    }
    double minMaxDist(vector<int> &stations, int K)
    {

        long double low = 0;
        long double high = 0;
        for (int i = 1; i < stations.size(); i++)
        {
            high = max(high, (long double)(stations[i] - stations[i - 1]));
        }
        while (high - low > 1e-6)
        {
            long double mid = (low + high) / 2;
            int reqGS = nofGSreq(mid, stations);
            if (reqGS > K)
                low = mid;
            else
                high = mid;
        }
        return high;
    }
};
