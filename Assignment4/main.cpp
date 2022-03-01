/***************************************************

Allen Valdez - CS110B

***************************************************/

#include <iostream>
#include <vector>

using namespace std;
// Variables I will use
int timesElementsAccessed{0}, mergeSortElementsAccessed{0}, countSortElementsAccessed{0};
vector<int> bubbleSort(vector<int> array);

vector<int> bubbleSort(vector<int> array)
{
  if (array.empty())
  {
    cout << "Uhh... this is empty boss" << endl;
    return {};
  }
  bool isSorted{false};
  int counter = 0;

  while (!isSorted)
  {
    isSorted = true;
    for (int i{0}; i < array.size() - 1 - counter; i++)
    {
      if (array[i] > array[i + 1])
      {
        swap(array[i], array[i + 1]);
        timesElementsAccessed += 2; // This is because we accessed the elements twice to swap
        isSorted = false;
      }
      timesElementsAccessed += 2; // This because in the if statement we accessed it twice to check
    }
    counter++;
  }
  return array;
}

// Merge Sort
vector<int> mergeSortedArrays(vector<int> leftHalf, vector<int> rightHalf);

vector<int> mergeSort(vector<int> array)
{
  if (array.size() <= 1)
  {
    return array;
  }
  int middleIdx = array.size() / 2;
  vector<int> leftHalf(array.begin(), array.begin() + middleIdx);
  vector<int> rightHalf(array.begin() + middleIdx, array.end());
  return mergeSortedArrays(mergeSort(leftHalf), mergeSort(rightHalf));
}

vector<int> mergeSortedArrays(vector<int> leftHalf, vector<int> rightHalf)
{
  vector<int> sortedArray(leftHalf.size() + rightHalf.size(), 0);
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < leftHalf.size() && j < rightHalf.size())
  {
    if (leftHalf[i] <= rightHalf[j])
    {
      sortedArray[k++] = leftHalf[i++];
      mergeSortElementsAccessed++;
    }
    else
    {
      sortedArray[k++] = rightHalf[j++];
      mergeSortElementsAccessed++;
    }
  }
  while (i < leftHalf.size())
  {
    sortedArray[k++] = leftHalf[i++];
    mergeSortElementsAccessed++;
  }
  while (j < rightHalf.size())
  {
    sortedArray[k++] = rightHalf[j++];
    mergeSortElementsAccessed++;
  }
  return sortedArray;
}

void countSort(int array[], int n)
{
  const int range{100};
  int *count = new int[range + 1];
  for (int i = 0; i <= range; i++)
  {
    count[i] = 0;
    countSortElementsAccessed++;
  }
  for (int i = 0; i < n; i++)
  {
    count[array[i]]++;
    countSortElementsAccessed++;
  }
  for (int i = 0, j = 0; i <= range;)
  {
    if (count[i] > 0)
    {
      array[j] = i;
      j++;
      count[i]--;
      countSortElementsAccessed += 3;
    }
    else
    {
      i++;
    }
  }
}

int main()
{
  // Test Arrays for Bubble Sort
  int bubbleTest1[8], bubbleTest2[32], bubbleTest3[128];
  // Test Arrays for Merge Sorts
  int mergeTest1[8], mergeTest2[32], mergeTest3[128];
  // Test Arrays for Counting Sort
  int countingTest1[8], countingTest2[32], countingTest3[128];
  // Randomizing my test arrays
  srand(time(NULL));
  for (int i{0}; i < 8; i++)
  {
    bubbleTest1[i] = (rand() % 101);
    mergeTest1[i] = (rand() % 101);
    countingTest1[i] = (rand() % 101);
  }
  for (int i{0}; i < 32; i++)
  {
    bubbleTest2[i] = (rand() % 101);
    mergeTest2[i] = (rand() % 101);
    countingTest2[i] = (rand() % 101);
  }
  for (int i{0}; i < 128; i++)
  {
    bubbleTest3[i] = (rand() % 101);
    mergeTest3[i] = (rand() % 101);
    countingTest3[i] = (rand() % 101);
  }
  // Wanted to try something new and convert it to vectors
  int bubbleTestOneLength = sizeof(bubbleTest1) / sizeof(bubbleTest1[0]);
  vector<int> bubbleSort1(bubbleTest1, bubbleTest1 + bubbleTestOneLength);

  int bubbleTestTwoLength = sizeof(bubbleTest2) / sizeof(bubbleTest2[0]);
  vector<int> bubbleSort2(bubbleTest2, bubbleTest2 + bubbleTestTwoLength);

  int bubbleTestThreeLength = sizeof(bubbleTest3) / sizeof(bubbleTest3[0]);
  vector<int> bubbleSort3(bubbleTest3, bubbleTest3 + bubbleTestThreeLength);

  cout << "*****************START OF ANALYSIS FOR BUBBLE SORT*****************" << endl;
  cout << endl;
  cout << "Sort Algorithm		|		Array Length 		| Array Accesses Pass 1		| Array Accesses Pass 2		| Array Accesses Pass 3		| Average Array Accessess" << endl;
  //	BUBBLE SORT 1
  bubbleSort(bubbleSort1);
  int bubbleSortElement1 = timesElementsAccessed;

  bubbleSort(bubbleSort1);
  int bubbleSortElement2 = timesElementsAccessed;

  bubbleSort(bubbleSort1);
  int bubbleSortElement3 = timesElementsAccessed;
  double averageBubbleSort{(bubbleSortElement1 + bubbleSortElement2 + bubbleSortElement3) / 3};

  cout << "Bubble Sort			|				" << bubbleTestOneLength << "			|			" << bubbleSortElement1 << "				|				" << bubbleSortElement2 << "			|			" << bubbleSortElement3 << "				|			" << averageBubbleSort << endl;
  // RESETTING
  timesElementsAccessed = 0;
  bubbleSortElement1 = 0;
  bubbleSortElement2 = 0;
  bubbleSortElement3 = 0;
  averageBubbleSort = 0;

  //	BUBBLE SORT 2
  bubbleSort(bubbleSort2);
  bubbleSortElement1 = timesElementsAccessed;

  bubbleSort(bubbleSort2);
  bubbleSortElement2 = timesElementsAccessed;

  bubbleSort(bubbleSort2);
  bubbleSortElement3 = timesElementsAccessed;
  averageBubbleSort = ((bubbleSortElement1 + bubbleSortElement2 + bubbleSortElement3) / 3);

  bubbleSort(bubbleSort2);
  cout << "Bubble Sort			|				" << bubbleTestTwoLength << "			|			" << bubbleSortElement1 << "			|				" << bubbleSortElement2 << "		|			" << bubbleSortElement3 << "			|			" << averageBubbleSort << endl;
  // RESETTING
  timesElementsAccessed = 0;
  bubbleSortElement1 = 0;
  bubbleSortElement2 = 0;
  bubbleSortElement3 = 0;
  averageBubbleSort = 0;

  //	BUBBLE SORT 3
  bubbleSort(bubbleSort3);
  bubbleSortElement1 = timesElementsAccessed;

  bubbleSort(bubbleSort3);
  bubbleSortElement2 = timesElementsAccessed;

  bubbleSort(bubbleSort3);
  bubbleSortElement3 = timesElementsAccessed;
  averageBubbleSort = ((bubbleSortElement1 + bubbleSortElement2 + bubbleSortElement3) / 3);

  bubbleSort(bubbleSort3);
  cout << "Bubble Sort			|				" << bubbleTestThreeLength << "			|			" << bubbleSortElement1 << "			|				" << bubbleSortElement2 << "		|			" << bubbleSortElement3 << "			|			" << averageBubbleSort << endl;
  cout << endl;
  cout << "Time Complexity: O(n^2)" << endl;
  cout << endl;
  cout << "*****************END OF ANALYSIS FOR BUBBLE SORT*****************" << endl;

  cout << endl;
  cout << endl;

  int mergeTestOneLength = sizeof(mergeTest1) / sizeof(mergeTest1[0]);
  vector<int> mergeSort1(mergeTest1, mergeTest1 + mergeTestOneLength);

  int mergeTestTwoLength = sizeof(mergeTest2) / sizeof(mergeTest2[0]);
  vector<int> mergeSort2(mergeTest2, mergeTest2 + mergeTestTwoLength);

  int mergeTestThreeLength = sizeof(mergeTest3) / sizeof(mergeTest3[0]);
  vector<int> mergeSort3(mergeTest3, mergeTest3 + mergeTestThreeLength);

  cout << "*****************START OF ANALYSIS FOR MERGE SORT*****************" << endl;
  cout << endl;
  cout << "Sort Algorithm		|		Array Length 		| Array Accesses Pass 1		| Array Accesses Pass 2		| Array Accesses Pass 3		| Average Array Accessess" << endl;

  mergeSort(mergeSort1);
  int mergeSortElement1 = mergeSortElementsAccessed;

  mergeSort(mergeSort1);
  int mergeSortElement2 = mergeSortElementsAccessed;

  mergeSort(mergeSort1);
  int mergeSortElement3 = mergeSortElementsAccessed;
  double averageMergeSort{(mergeSortElement1 + mergeSortElement2 + mergeSortElement3) / 3};

  cout << "Merge Sort			|				" << mergeTestOneLength << "			|			" << mergeSortElement1 << "				|				" << mergeSortElement2 << "			|			" << mergeSortElement3 << "				|			" << averageMergeSort << endl;
  // RESETTING
  timesElementsAccessed = 0;
  mergeSortElement1 = 0;
  mergeSortElement2 = 0;
  mergeSortElement3 = 0;
  averageMergeSort = 0;

  mergeSort(mergeSort2);
  mergeSortElement1 = mergeSortElementsAccessed;

  mergeSort(mergeSort2);
  mergeSortElement2 = mergeSortElementsAccessed;

  mergeSort(mergeSort2);
  mergeSortElement3 = mergeSortElementsAccessed;
  averageMergeSort = ((mergeSortElement1 + mergeSortElement2 + mergeSortElement3) / 3);

  cout << "Merge Sort			|				" << mergeTestTwoLength << "			|			" << mergeSortElement1 << "				|				" << mergeSortElement2 << "			|			" << mergeSortElement3 << "				|			" << averageMergeSort << endl;

  // RESETTING
  timesElementsAccessed = 0;
  mergeSortElement1 = 0;
  mergeSortElement2 = 0;
  mergeSortElement3 = 0;
  averageMergeSort = 0;

  mergeSort(mergeSort3);
  mergeSortElement1 = mergeSortElementsAccessed;

  mergeSort(mergeSort3);
  mergeSortElement2 = mergeSortElementsAccessed;

  mergeSort(mergeSort3);
  mergeSortElement3 = mergeSortElementsAccessed;
  averageMergeSort = ((mergeSortElement1 + mergeSortElement2 + mergeSortElement3) / 3);

  cout << "Merge Sort			|				" << mergeTestThreeLength << "			|			" << mergeSortElement1 << "			|				" << mergeSortElement2 << "		|			" << mergeSortElement3 << "			|			" << averageMergeSort << endl;
  cout << endl;
  cout << "Time Complexity: O(nlog(n))" << endl;
  cout << endl;
  cout << "*****************END OF ANALYSIS FOR MERGE SORT*****************" << endl;
  cout << endl;
  cout << endl;

  int countTestOneLength = sizeof(countingTest1) / sizeof(countingTest1[0]);
  vector<int> countingSort1(countingTest1, countingTest1 + countTestOneLength);

  int countTestTwoLength = sizeof(countingTest2) / sizeof(countingTest2[0]);
  vector<int> countingSort2(countingTest2, countingTest2 + countTestTwoLength);

  int countTestThreeLength = sizeof(countingTest3) / sizeof(countingTest3[0]);
  vector<int> countingSort3(countingTest3, countingTest3 + countTestThreeLength);
  cout << "*****************START OF ANALYSIS FOR COUNTING SORT*****************" << endl;
  cout << endl;
  cout << "Sort Algorithm		|		Array Length 		| Array Accesses Pass 1		| Array Accesses Pass 2		| Array Accesses Pass 3		| Average Array Accessess" << endl;
  countSort(countingTest1, countTestOneLength);
  int countSortElement1 = countSortElementsAccessed;

  countSort(countingTest1, countTestOneLength);
  int countSortElement2 = countSortElementsAccessed;

  countSort(countingTest1, countTestOneLength);
  int countSortElement3 = countSortElementsAccessed;
  double averageCountSort{(countSortElement1 + countSortElement2 + countSortElement3) / 3};

  cout << "Count Sort			|				" << countTestOneLength << "			|			" << countSortElement1 << "			|				" << countSortElement2 << "		|			" << countSortElement3 << "			|			" << averageCountSort << endl;

  // // RESETTING
  countSortElementsAccessed = 0;
  countSortElement1 = 0;
  countSortElement2 = 0;
  countSortElement3 = 0;
  averageCountSort = 0;

  countSort(countingTest2, countTestTwoLength);
  countSortElement1 = countSortElementsAccessed;

  countSort(countingTest2, countTestTwoLength);
  countSortElement2 = countSortElementsAccessed;

  countSort(countingTest2, countTestTwoLength);
  countSortElement3 = countSortElementsAccessed;
  averageCountSort = ((countSortElement1 + countSortElement2 + countSortElement3) / 3);

  cout << "Count Sort			|				" << countTestTwoLength << "			|			" << countSortElement1 << "			|				" << countSortElement2 << "		|			" << countSortElement3 << "			|			" << averageCountSort << endl;

  // RESETTING
  countSortElementsAccessed = 0;
  countSortElement1 = 0;
  countSortElement2 = 0;
  countSortElement3 = 0;
  averageCountSort = 0;

  countSort(countingTest3, countTestThreeLength);
  countSortElement1 = countSortElementsAccessed;

  countSort(countingTest3, countTestThreeLength);
  countSortElement2 = countSortElementsAccessed;

  countSort(countingTest3, countTestThreeLength);
  countSortElement3 = countSortElementsAccessed;
  averageCountSort = ((countSortElement1 + countSortElement2 + countSortElement3) / 3);

  cout << "Count Sort			|				" << countTestThreeLength << "			|			" << countSortElement1 << "			|			" << countSortElement2 << "		|		" << countSortElement3 << "			|			" << averageCountSort << endl;
  cout << endl;

  cout << "Time Complexity: O(max(Range,N))";
  cout << endl;
  cout << "*****************END OF ANALYSIS FOR COUNTING SORT*****************" << endl;
  cout << endl;
}

/***************************************************
                    SAMPLE OUTPUT:
  *****************START OF ANALYSIS FOR BUBBLE SORT*****************

  Sort Algorithm      |       Array Length        | Array Accesses Pass 1     | Array Accesses Pass 2     | Array Accesses Pass 3     | Average Array Accessess
  Bubble Sort         |               8           |           78              |               156         |           234             |           156
  Bubble Sort         |               32          |           1306            |               2612        |           3918            |           2612
  Bubble Sort         |               128         |           25416           |               50832       |           76248           |           50832

  Time Complexity: O(n^2)

  *****************END OF ANALYSIS FOR BUBBLE SORT*****************


  *****************START OF ANALYSIS FOR MERGE SORT*****************

  Sort Algorithm      |       Array Length        | Array Accesses Pass 1     | Array Accesses Pass 2     | Array Accesses Pass 3     | Average Array Accessess
  Merge Sort          |               8           |           24              |               48          |           72              |           48
  Merge Sort          |               32          |           232             |               392         |           552             |           392
  Merge Sort          |               128         |           1448            |               2344        |           3240            |           2344

  Time Complexity: O(nlog(n))

  *****************END OF ANALYSIS FOR MERGE SORT*****************


  *****************START OF ANALYSIS FOR COUNTING SORT*****************

  Sort Algorithm      |       Array Length        | Array Accesses Pass 1     | Array Accesses Pass 2     | Array Accesses Pass 3     | Average Array Accessess
  Count Sort          |               8           |           133         |               266     |           399         |           266
  Count Sort          |               32          |           229         |               458     |           687         |           458
  Count Sort          |               128         |           613         |           1226        |       1839            |           1226

  Time Complexity: O(max(Range,N))
  *****************END OF ANALYSIS FOR COUNTING SORT*****************

***************************************************/