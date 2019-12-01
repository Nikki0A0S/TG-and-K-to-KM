//https://leetcode.com/problems/word-ladder-ii/

class Solution {
    public:
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set< string > dict( wordList.begin(), wordList.end() );
            dict.erase( beginWord );
            queue< vector< string > > q;
            vector< vector< string > > result;
            q.push( { beginWord } );
            bool found = false;
            while( !q.empty() ) {
                int size = q.size();
                unordered_set< string > nextLevel;

                for( int i = 0 ; i < size ; ++i ) {
                    vector< string > currLevel = q.front();
                    q.pop();
                    string currWord = currLevel.back();
                    if( currWord == endWord ) {
                        found = true;
                        result.push_back( currLevel );
                    } else {
                        for( int i = 0 ; i < currWord.size() ; ++i ) {
                            char orig = currWord[ i ];
                            for( char ch = 'a' ; ch <= 'z' ; ++ch ) {
                                if( ch == orig ) continue;
                                currWord[ i ] = ch;
                                if( dict.find( currWord ) != dict.end() ) {
                                    nextLevel.insert( currWord );
                                    q.push( currLevel );
                                    q.back().push_back( currWord );
                                }
                            }
                            currWord[ i ] = orig;
                        }
                    }
                }
                if( found ) break;
                for( auto n : nextLevel ) {
                    dict.erase( n );
                }
            }
            return result;
        }

};