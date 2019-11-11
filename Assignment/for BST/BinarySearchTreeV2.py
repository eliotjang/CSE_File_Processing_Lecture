'''
Author: Eliot Jang(장성원)
last_modified_at: 2019-11-11
'''

#인자로 받은 data를 인스턴스 data에 저장하고 left,right변수를 초기화하는 class 생성
class Node(object):
    def __init__(self, data):
        self.data = data
        self.left = self.right = None

#이원탐색트리 class 생성
class BinarySearchTree(object):
    #인스턴스 root node를 초기화
    def __init__(self):
        self.root = None
    #해당 data를 bst 인스턴스 root에 삽입
    def insert(self, data):
        self.root = self._insert_value(self.root, data)
        # root node에 어떠한 값이 있다면 True 반환
        return self.root is not None

    def _insert_value(self, node, data):
        #root node에 아무런 값도 없다면 nonde 인스턴스에 data를 그대로 삽입
        if node is None:
            node = Node(data)
        else:
            #해당 node의 데이터가 입력받은 data보다 작다면 
            if data <= node.data:
                #child tree인 왼쪽 트리로 가는 node 인스턴스의 left변수와 해당 data를 인자로 넣는 재귀함수 호출
                node.left = self._insert_value(node.left, data)
            else:
                #child tree인 오른쪽 트리로 가는 node 인스턴스의 right변수와 해당 data를 인자로 넣는 재귀함수 호출
                node.right = self._insert_value(node.right, data)
        #node가 만들어졌다면 해당 node 인스턴스를 반환
        return node
    #해당 데이터인 key와 새롭게 만든 result배열을 인자로 받아 find 메소드 생성
    def find(self, key, result):
        #해당 데이터가 어디 있는지 찾아주는 메소드를 호출하여 반환
        return self._find_value(self.root, key, result)
    #해당 node와 key 그리고 새롭게 만든 result배열을 인자로 받은 _find_value 메소드 생성
    def _find_value(self, root, key, result):
        #root node가 없거나 root node의 data가 입력받은 data인 key와 일치한다면
        if root is None or root.data == key:
            #해당 데이터 출력
            print("\n해당 배열의 데이터는", root.data,"\n데이터에 해당하는 배열의 첨자는 ",end='')
            #데이터에 해당하는 배열의 첨자 출력후 반환
            return result.index(root.data)
        #찾고자 하는 data인 key가 root node보다 작다면
        elif key < root.data:
            #root 인스턴스의 child tree인 왼쪽으로 가는 트리인 left 변수, 해당 data인 key, 새롭게 만든 result 배열의 인자로 재귀함수 호출
            return self._find_value(root.left, key, result)
        else:
            #root 인스턴스의 child tree인 오른쪽으로 가는 트리인 right 변수, 해당 data인 key, 새롭게 만든 result 배열의 인자로 재귀함수 호출
            return self._find_value(root.right, key, result)
    #왼쪽 하위 트리를 모두 방문하고 root를 방문하고 마지막으로 오른쪽 하위 트리를 모두 방문하여 오름차순으로 정렬하는 중위순회 메소드 생성
    def in_order_traversal(self, result):
        #중위순회 메소드 구현
        def _in_order_traversal(root, result):
            #root node가 null값이라면
            if root is None:
                #그대로 진행
                pass
            else:
                #root node가 null값이 아니라면 왼쪽 서브트리를 방문
                _in_order_traversal(root.left,result)
                #result 배열에 data 추가
                result.append(root.data)
                #배열의 첨자와 data값 출력
                print('[',array.index(root.data),']', root.data)
                #root node의 오른쪽 서브 트리 방문
                _in_order_traversal(root.right,result)
        #root node 자기 자신을 순회
        _in_order_traversal(self.root,result)

if __name__ == '__main__':
    #초기 데이터 값
    array = [15, 11, 70, 5, 13, 50, 18, 30, 1]
    #최종 결과를 넣는 배열 초기화
    result = []

    print("초기 배열")
    print(array)
    #이원탐색트리 메소드 호출
    bst = BinarySearchTree()
    #데이터 값을 이원탐색트리에 삽입
    for x in array:
        bst.insert(x)

    print("\n초기 배열이 이원탐색트리에 의해 정렬 되는 과정")
    bst.in_order_traversal(result)

    print("\n이원탐색트리를 적용한 새로운 배열")
    print(result)
    for a in result:
        print('[',result.index(a),']',a)

    while True:
        x = input("\n검색하고자하는 데이터를 입력하세요")
        int_x = int(x)
        print(bst.find(int_x,result))