#include <iostream>
#include <list>
#include <stack>

using namespace std;
/*
1-365
//val coverages = List( Cov(1, 20), Cov(21, 30), Cov(15, 25), Cov(28, 40), Cov(50, 60), Cov(61, 200)
1-20 21- 30 40  50 60 61 200
 
*/

class Coverage 
{ 
    public:	
        Coverage(int start, int end):m_startDay(start),m_endDay(end) {}
	
        Coverage(const Coverage& cov) {
            m_startDay = cov.m_startDay;
             m_endDay = cov.m_endDay;
        }
	
        int getStartDay() {return m_startDay;}
        void setStartDay(int start) {m_startDay = start;}
        
        int getEndDay() {return m_endDay;}
        void setEndDay(int end) {m_endDay = end;}
        
        int getCoverageInterval() { return m_endDay - m_startDay;}
        
        friend bool operator < (Coverage const &c1, Coverage const &c2) {return c1.m_startDay < c2.m_startDay ;}
    private:
        int m_startDay;
        int m_endDay; 
       
}; 
  

  

// The main function that takes a list of coverages, merges 
// overlapping coverages and prints the result 
Coverage getLongestCoverage(list<Coverage>& coverages) 
{ 
    // Test if the given set has at least one interval 
    if (coverages.size() <= 0) 
        return; 
  
    // Create an empty stack of intervals 
    stack<Coverage> s; 
  
    // sort the intervals in increasing order of start time 
    coverages.sort();
    
     list<Coverage>::iterator it;
   // push the first Coverage to stack 
    s.push(*coverages.begin()); 
  
  //sotre the longest coverage in this memebr
  Coverage longestCoverage(*coverages.begin());
     // Start from the next interval and merge if necessary 
   for (it=coverages.begin(); it!=coverages.end(); ++it)
    { 
        // get Coverage from stack top 
        Coverage top(s.top()); 
  
        // if current Coverage is not overlapping with stack top, 
        // push it to the stack 
        if (top.getEndDay() <= (*it).getStartDay())  {
            s.push(*it); 
            //if new coverage interval bigger then current longest one
            if (longestCoverage.getCoverageInterval() < (*it).getCoverageInterval()) {
                longestCoverage.setStartDay((*it).getStartDay());
                longestCoverage.setEndDay((*it).getEndDay());
            }
        }
        // Otherwise update the ending date of top if ending of current 
        // Coverage is more 
        else if (top.getEndDay() <= (*it).getEndDay()) 
        { 
            top.setEndDay((*it).getEndDay()); 
            s.pop(); 
            s.push(top); 
            //if new coverage interval bigger then current longest one
             //if new coverage interval bigger then current longest one
            if (longestCoverage.getCoverageInterval() < top.getCoverageInterval()) {
                longestCoverage.setStartDay(top.getStartDay());
                longestCoverage.setEndDay(top.getEndDay());
            }
        } 
    } 
  
    // Print contents of stack 
    cout << "\n The Merged Coverages are: "; 
    while (!s.empty()) 
    { 
        Coverage t = s.top(); 
        cout << "[" << t.getStartDay() << "," << t.getEndDay() << "] "; 
        s.pop(); 
    }     
    return longestCoverage; 
} 

int main(void){
    // Your code here!
    list<Coverage>::iterator it;
    cout << "Hello!" << std::endl;
   list<Coverage> inputCoverages = {Coverage(1, 20), Coverage(21, 30), Coverage(15, 25), Coverage(28, 40), Coverage(50, 60), Coverage(61, 200)};
   
  
  Coverage longestCoverage = getLongestCoverage(inputCoverages);
  cout << "Longest Coverage is " << longestCoverage.getCoverageInterval() << " from " << longestCoverage.getStartDay() << " To " << longestCoverage.getEndDay() << endl;
}




