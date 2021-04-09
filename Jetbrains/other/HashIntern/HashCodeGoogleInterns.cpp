#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#define ll long long

using namespace std;
string INPUT_FILE_NAME = "C:/Users/Alex Li/CLionProjects/ProgrammingContests/CLion/HashIntern/vlogger.in";
string OUTPUT_FILE_NAME = "C:/Users/Alex Li/CLionProjects/ProgrammingContests/CLion/HashIntern/solution.out";

struct Cache {
    // ID of this cache.
    int id;
    // A list of the cached videos by index.
    // id
    unordered_set<int> cached;

    // A set of all endpoints that connect to this map
    // id -> latency
    unordered_map<int, int> endpoints;
};

struct Endpoint {
    // Latency of this endpoint to the current cache.
    // video -> latency.
//    int latency;
    unordered_map<int, int> latencies = unordered_map<int, int>();


    // A mapping of each connection to a cache
    // cache ID -> latency
    unordered_map<int, int> caches = unordered_map<int, int>();

    // A mapping of video ID to number of requests
    // video ID -> # of requests
    unordered_map<int, int> requests = unordered_map<int,int>();
};

vector<int> videos;
vector<Cache> caches;
vector<Endpoint> endpoints;
int cacheCapacity;

void greedy() {
    // Modify caches variable by adding 'cached' parameter
    // For each cache: Sort the videos by 'value'.
    for(auto& cache : caches){
        // vector of (value, index) pairs for the videos
        vector<pair<double, int>> values;
        for(int i = 0; i < videos.size(); i++){
            values.push_back(pair<double, int>(0, i));
        }
        for(auto& end : cache.endpoints){
            int endID = end.first;
            int cacheLatency = end.second;
            // Look in the endpoint for this video, if it exists then the value increases
            for(auto & videoRequestPair : endpoints[endID].requests){
                int video = videoRequestPair.first;
                int requestCount = videoRequestPair.second;
                double timeSaved = max(0, endpoints[endID].latencies[video] - cacheLatency);
                values[video].first += ((requestCount * timeSaved) / videos[video]);
            }
        }
        sort(values.begin(), values.end(), greater<pair<double, int>>());
        int capLeft = cacheCapacity;
        int ind = 0;
        while(ind < values.size()){
            if(capLeft >= videos[values[ind].second]){
                // store in cache cached variable
                int video = values[ind].second;
                cache.cached.insert(video);
                capLeft -= videos[video];
                for(auto& end : cache.endpoints){
                    Endpoint* endpoint = &(endpoints[end.first]);
                    endpoint->latencies[video] = min(endpoint->latencies[video], end.second);
                }
            }
            ++ind;
        }
    }
}

void input(string filename) {
    int numVideos;
    int numEndpoints;
    int numRequests;
    int numCaches;
    ifstream input;
    input.open(filename);
    input.tie(nullptr);

    // initialize vectors
    input >> numVideos;
    input >> numEndpoints;
    input >> numRequests;
    input >> numCaches;
    input >> cacheCapacity;
    videos = vector<int>(numVideos);
    endpoints = vector<Endpoint>(numEndpoints);
    caches = vector<Cache>(numCaches);
    for (int i = 0; i < numCaches; i++) {
        caches[i].id = i;
        caches[i].cached = unordered_set<int>();
        caches[i].endpoints = unordered_map<int, int>();
    }

    for (int i = 0; i < numVideos; i++) {
        input >> videos[i];
    }

    for (int i = 0; i < numEndpoints; i++) {
        endpoints[i] = Endpoint();
        int latency;
        input >> latency;
        for (int j = 0; j < numVideos; j++) {
            endpoints[i].latencies[j] = latency;
        }
        int numEndpointCaches;
        input >> numEndpointCaches;
        endpoints[i].caches = unordered_map<int, int>();
        endpoints[i].requests = unordered_map<int, int>();

        // latencies
        for (int j = 0; j < numEndpointCaches; j++) {
            int cache;
            int latency;
            input >> cache;
            input >> latency;
            endpoints[i].caches[cache] = latency;
            caches[cache].endpoints[i] = latency;
        }
    }

    // requests
    for (int i = 0; i < numRequests; i++) {
        int video;
        int endpoint;
        int count;
        input >> video;
        input >> endpoint;
        input >> count;
        endpoints[endpoint].requests[video] = count;
    }

    input.close();
}

void output() {
    ofstream out;
    out.tie(nullptr);
    out.open(OUTPUT_FILE_NAME);
    // use out, not cout

    int numOfCachesUsed = 0;
    for (auto cache : caches) {
        if (cache.cached.size() > 0)
            ++numOfCachesUsed;
    }

    out << numOfCachesUsed << endl;

    for (int i = 0; i < caches.size(); ++i) {
        if (caches[i].cached.size() > 0) {
            out << i << " ";
            for (auto video : (caches[i].cached)) {
                out << video << " ";
            }
            out << endl;
        }
    }

    out.close();
}

int main() {
    input(INPUT_FILE_NAME);
    greedy();
    output();
}

