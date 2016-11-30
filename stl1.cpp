#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
//Container types (and algorithms, functors and all STL as well) are defined not in global namespace, but in special namespace called “std.”




/**
When the program is using STL, it should #include the appropriate standard headers. For most containers the title of standard header matches the name of the container, and no extension is required. For example, if you are going to use stack, just add the following line at the beginning of your program:
#include <stack>
*/
using namespace std;
/**
Another important thing to remember is that the type of a container is the template parameter. Template parameters are specified with the ‘<’/’>’ “brackets” in code. For example:
vector<int> N;
*/
/**VECTors
.............................
When making nested constructions, make sure that the “brackets” are not directly following one another – leave a blank between them.
vector< vector<int> >
 vector<int> v[10]; 
Here we declare ‘v’ as an array of 10 vector<int>’s, which are initially empty. In most cases, this is not that we want. Use parentheses instead of brackets here. that is vector<int> v(10);
functions in vectors
1. v.size()
2. v.empty()
3. v.pushback() Push_back adds an element to the end of vector, increasing its size by one. 
4. v.resize(newsizze)  The resize() function makes vector contain the required number of elements. If you require less elements than vector already contain, the last ones will be deleted. If you ask vector to grow, it will enlarge its size and fill the newly created elements with zeroes.
5. v.clear() this function makes vector to contain 0 elements. It does not make elements zeroes -- watch out -- it completely erases the container.
6. v.insert()
7. v.erase()
 INTIALISATIONS OF VECTORS
 vector<int> v1;
 vector<int> v2(v1) initialisation of a vector using already initialesd vectors
 vector<int> v2=v1;
 vector<int> Data(1000); 
 vector<int> v(10,5); this initialisations vector with 5
  vector<int> v3(v.begin(), v.end()); // v3 equals to v2 
  vector<int> v2(v.begin(), v.begin() + (v.size()/2)); 

In the example above, the data will contain 1,000 zeroes after creation. Remember to use parentheses, not brackets. If you want vector to be initialized with something else, write it in such manner:
 vector<string> names(20, “Unknown”); 
 TwO dimenSIONAL VECTors..................
 vector< vector<int> > Matrix(N, vector<int>(M, -1));
 
 
 
 
 PASIING  vector AS A ARGUMENT TO A FUNCTION.....
 void some_function(vector<int> v) will create a copy of vector..DONOT do it.
 instead use void some_function(const vector<int>& v) ...but if one ned to make changes to a  vector omit he const term
 int modify_vector(vector<int>& v)
 
*/
#define all(c) c.begin(), c.end()
#define tr(container,it)\
    for(typeof(container.begin()) it= container.begin();it!=container.end();it++)
int main(){
   int i;
   
  
  int data[]={2,33,4,55,6,7,22,2,0,55,1,11,44,4,0};
  vector<int> v(data,data+15);
  tr(v,it){
    cout<<(*it)<<" ";}
    cout<<endl;
  set<int> s(all(v));
  cout<<"elements of set:";
  
  tr(s,it){
   cout<<*it<<" ";}
   cout<<endl;
  
  vector<int> v2(all(s));
  
   tr(v2,it){
   cout<<*it<<" ";} 
   cout<<endl;
   
    
   
    
   
  /**int i; 
  vector<int> v(10,5);
  for(i=0;i<v.size();i++)cout<<v[i]<<" ";
  
  for(i=0;i<10;i++)v[i]=2*i;
  cout<<"the size of vector="<<v.size()<<endl;
  if(v.empty())cout<<"the given vector is empty"<<endl;
  v.push_back(444);
  cout<<"vector after pushingback 444="<<endl;
  for(i=0;i<v.size();i++)cout<<v[i]<<" ";
  cout<<"resizing hte vector to 20";
  v.resize(20);
  cout<<"the changed vector size="<<v.size()<<endl;
  for(i=0;i<v.size();i++)cout<<v[i]<<" ";
  vector<int> v2=v;
  v.clear();
  if(v.empty())cout<<"the given vector is empty";
  cout<<"the othr vector v2="<<endl;
  for(i=0;i<v2.size();i++)
  cout<<v2[i]<<endl;*/
  return 0;
  
  }
  /**   
  PAIRS is another containr...
  template<typename1 T1,TYpename2 T2> struct pair{
  T1 first;
  T2 second;
  }
  pair<int,int> x;
  pair<string, pair<int,int> > P;
  
  COMPARISON OF PAIRS!!!
  The great advantage of pairs is that they have built-in operations to compare themselves. Pairs are compared first-to-second element. If the first elements are not equal, the result will be based on the comparison of the first elements only; the second elements will be compared only if the first ones are equal. The array (or vector) of pairs can easily be sorted by STL internal functions.
  
  **PAIRS DO NOTHAVE ITERATORS..(http://stackoverflow.com/questions/13749569/why-doesnt-stdpair-have-iterators)
  
  */
  
  /**
  ITERATORS.
  .......................
   In STL iterators are the most general way to access data in containers.
   Each container also has the rbegin()/rend() functions, which return reverse iterators. Reverse iterators are used to traverse the container in backward order.vector<int> v2(v.rbegin()+(v.size()/2), v.rend()); 
will create v2 with first half of v, ordered back-to-front.
   
    iterators are objects that can take value (unary *), comparison (<),!=, and increment/decrement (++/–). Objects with these properties that are associated with containers are called iterators. Any STL container may be traversed by means of an iterator. Although not often needed for vector, it’s very important for other container types.
    In simple words we can say that iterators are  objects with syntax much like pointers.
    But instead of pointers, iterators provide much greater functionality. Not only can they operate on any container, they may also perform, for example, range checking and profiling of container usage.
And the main advantage of iterators, of course, is that they greatly increase the reuse of code: your own algorithms, based on iterators, will work on a wide range of containers, and your own containers, which provide iterators, may be passed to a wide range of standard functions.

   TYpes of iterators.
   1.normal iterators.
   2.random access iterators.(http://en.cppreference.com/w/cpp/concept/RandomAccessIterator)    
   normal iterators may be compared with ‘==’ and ‘!=’, and they may also be incremented and decremented. They may not be subtracted and we can not add a value to the normal iterator.
   ***STL algorithms always use two iterators, called “begin” and “end.” The end iterator is pointing not to the last object, however, but to the first invalid object, or the object directly following the last one. It’s often very convenient.
   Each STL container has member functions begin() and end() that return the begin and end iterators for that container.
   **c.begin()==c.end()only if the container is empty.and c.end() – c.begin() will always be equal to c.size(). (The last sentence is valid in  cases when iterators can be subtracted, i.e. begin() and end() return random access iterators, which is not true for all kinds of containers.
   
   
   
   INTIALISATION OF ITERATORS
   To create an iterator object, we must specify its type. The type of iterator can be constructed by a type of container by appending “::iterator”, “::const_iterator”, “::reverse_iterator” or “::const_reverse_iterator” (CONSTANT ITERATOR ARE USED WHEN A VECTOR IS PASSED TO A FUNCTION AS A CONSTANT REFERNCE say for example... void fucntion(const vector<int>& v)...to it. Thus, vector can be traversed in the following way:
  example of reverse iterator
  vector<int>::reverse_iterator itr;
  for(itr=v.rbegin();itr!=v.rend();itr++)
 
  for(vector<int>::iterator it=v.begin(),it!=v.end();it++){
   ............
   }
   
   
  */
  
  
  /**
  FUNCTIONS WITHIN #include<algorithm>
  
  
  a. reverse(iterator1,iterator2)
  for eg reverse(v.begin(),v.end())
  or we can use macros like 
  #define all(c) c.begin(), c.end()
  and callof reverse fucntion changes to reverse(all(v))//where vector<int> v;
   it have rbegin() and rend() functions
  b. find(it1,it2,elmnt)
  The find() algorithm looks for appropriate elements in an interval. If the element is found, the iterator pointing to the first occurrence of the element is returned. Otherwise, the return value equals the end of interval. See the code 
  c. min_element and max_element
     The min_element and max_element algorithms return an iterator to the respective element. To get the value of min/max element, like in find(), use *min_element(…) or *max_element(…), to get index in array subtract the begin iterator of a container or range:
     int v1 = *max_element(X.begin(), X.end());
  d. sort(it1,it2)
     sort(X.begin(), X.end()); // Sort array in ascending order 
     sort(all(X)); // Sort array in ascending order, use our #define 
     sort(X.rbegin(), X.rend()); // Sort array in descending order using with reverse iterators 
    
  */
   
   /**MACROS IN C++ ALSO KNOWN AS PREPROCESSOR DIRECTIVE
      REFERENCE http://www.cplusplus.com/doc/tutorial/preprocessor/
     FREQUENTLY USED MACROS......
 typedef vector<int> vi; 
 typedef vector<vi> vvi; 
 typedef pair<int,int> ii; 
 #define sz(a) int((a).size()) 
 #define pb push_back 
 #defile all(c) (c).begin(),(c).end() 
 #define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
 #define present(c,x) ((c).find(x) != (c).end()) 
 #define cpresent(c,x) (find(all(c),x) != (c).end()) 
      
      
      
      
      
      
      
      
      
      
      
      
      */  
  
  /**
  typeof(x) 
   the most important application of typeof for TopCoder is traversing a container. Consider the following macros:
 #define tr(container, it) \ 
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
  by using these macros we can traverse every kind of container, not only vector. This will produce const_iterator for const object and normal iterator for non-const object, and you will never get an error here.    
  
  Traversing macros is not really necessary for vectors, but it’s very convenient for more complex data types, where indexing is not supported and iterators are the only way to access data.   
      
      */
      
   /** SET CONTAINER IN C++
   
     set container is used when we require following functionalities....
     a. add element without creating duples
     b. remove a elemnt
     c. get count of the elemnts(disticnt elmnts)
     d. check whether a elmnt is present in set.
     Set can add, remove and check the presence of particular element in O(log N), where N is the count of objects in the set.
      While adding elements to set, the duples [duplicates?] are discarded. A count of the elements in the set, N, is returned in O(1).
      
      
      The push_back() member may not be used with set. It make sense: since the order of elements in set does not matter, push_back() is
       not applicable here.
      Since set is not a linear container, it’s impossible to take the element in set by index. Therefore, the only way to traverse the 
      elements of set is to use iterators. 
      
      
     find():To determine whether some element is present in set use ‘find()’ member function. Don’t be confused, though: there are several 
     ‘find()’ ’s in STL. There is a global algorithm ‘find()’, which takes two iterators, element, and works for O(N). It is possible to use it    
     for searching for element in set, but why use an O(N) algorithm while there exists an O(log N) one? While searching in set and map (and also 
     in multiset/multimap, hash_map/hash_set, etc.) do not use global find – instead, use member function ‘set::find()’. As ‘ordinal’ find, 
     set::find will return an iterator, either to the element found, or to ‘end()’. 
   
   erase() function
   
   INITIALISATION OF SETS
   set has a interval constructor
   int data[5]={5,1,4,3,2};
   set<int> s(data,data+5) note that here data+5 bcoz set.end() points to a null pointer like vectors.
   
   It gives us a simple way to get rid of duplicates in vector, and sort it:
    vector<int> v; 
    // … 
    set<int> s(all(v)); 
    vector<int> v2(all(s));
    .................................................
    #define all(c) c.begin(), c.end()
#define tr(container,it)\
    for(typeof(container.begin()) it= container.begin();it!=container.end();it++)
int main(){
   int i;
   
  
  int data[]={2,33,4,55,6,7,22,2,0,55,1,11,44,4,0};
  vector<int> v(data,data+15);
  tr(v,it){
    cout<<(*it)<<" ";}
    cout<<endl;
  set<int> s(all(v));
  cout<<"elements of set:";
  
  tr(s,it){
   cout<<*it<<" ";}
   cout<<endl;
  
  vector<int> v2(all(s));
  
   tr(v2,it){
   cout<<*it<<" ";} 
   cout<<endl;
   ......................................................................
   
    ANOTHER DATA STRUCTURE IMPLEMENTED IS MULTISET..CHECK IT OUT!!
    
    
    
  
  */
 
   
   
   
   

  
  
  
