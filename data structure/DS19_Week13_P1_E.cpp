#include<iostream>
#include<string>
using namespace std;
class vertex {
public:
	int vertex_id; //정점 고유번호
	int matrix_id; //정점의 edge matrix에서의 인덱스

	vertex* prev;
	vertex* next;

	vertex() { //디폴트 생성자 
		vertex_id = matrix_id = -1;
		prev = next = NULL;
	}
	vertex(int vertex_id) { //고유번호를 매개변수로 받는 생성자
		this->vertex_id = vertex_id;
		matrix_id = -1;
		prev = next = NULL;
	}
};

class edge { //간선 
public:
	vertex* src; //출발점
	vertex* dst; //조착점
	edge* prev; //간선시퀀스 앞
	edge* next; //뒤
	string message;
	edge() { //디폴트 생성자
		src = dst = NULL;
		prev = next = NULL;
		message = "";
	}
	edge(vertex* src, vertex* dst,string m) { //연결된 두 정점을 부여받는 생성자
		this->src = src;
		this->dst = dst;
		prev = next = NULL;
		message = m;
	}
};
class VertexList { //정점으로 이루어진 연결리스트 
public:
	vertex* header;
	vertex* trailer;


	VertexList() {
		header = new vertex();
		trailer = new vertex();
		header->next = trailer;
		trailer->prev = header;
	}
	void insert_back(vertex* new_vertex) { //뒤에 새 정점추가 

										   //원래 trailer전 정점- 추가한 정점-trailer 순으로 연결
		new_vertex->prev = trailer->prev;
		new_vertex->next = trailer;

		new_vertex->matrix_id = new_vertex->prev->matrix_id + 1;

		//이것도 구성 마저
		trailer->prev->next = new_vertex;
		trailer->prev = new_vertex;
		return;
	}

	void remove(vertex* del_vertex) {//정점리스트에서 정점제거 

									 //삭제하는 정점 다음거부터 행렬번호 하나씩 줄이기
		for (vertex* cur = del_vertex->next; cur != trailer; cur = cur->next)
			cur->matrix_id--;
		//삭제할 정점 앞뒤 정점 이어주기
		del_vertex->prev->next = del_vertex->next;
		del_vertex->next->prev = del_vertex->prev;
		//정점삭제
		delete del_vertex;
		return;
	}
	vertex* find_vertex(int vertex_id) { //정점 탐색 (정점의 고유번호) 
										 //리스트의 헤더부터 꼬리전까지 next로 가면서 탐색
		for (vertex* cur = header->next; cur != trailer; cur = cur->next)
			if (cur->vertex_id == vertex_id) return cur; //발견하면 리턴
		return NULL;
	}
};

class EdgeList { //간선으로 이루어진 이중연결리스트
public:
	edge* header;
	edge* trailer;

	EdgeList() { //디폴트 생성자
				 //헤더 트레일러 생성
		header = new edge();
		trailer = new edge();
		//둘 이어줌.
		header->next = trailer;
		trailer->prev = header;
	}
	//int length() {
	//	edge * e = header;
	//	int c=0;
	//	while (e->next != NULL) {
	//		e = e->next;
	//		c++;
	//	}
	//	return c;
	//}
	void insert_back(edge* new_edge) { //리스트 뒤에 새 간선 추가
									   //마지막에 달아주고 연결변경해주기
		new_edge->prev = trailer->prev;
		new_edge->next = trailer;
		trailer->prev->next = new_edge;
		trailer->prev = new_edge;
		return;
	}

	void remove(edge* del_edge) { //특정간선 제거 
								  //연결구조변경
		del_edge->prev->next = del_edge->next;
		del_edge->next->prev = del_edge->prev;
		delete del_edge; //삭제
		return;
	}

};
class graph { //그래프 클래스!
public:
	edge*** edge_matrix; //원소타입이 edge*인 이차원배열= edge정보를 관리하는 matrix 인접행렬
	VertexList vertex_list; //전체 정점을 관리하는 이중연결리스트
	EdgeList edge_list; //전체 간선을 관리하는 이중연결리스트
	int vertex_size = 0;; //그래프에 존재하는 정점개수 (행렬이 정점수*정점수 사이즈이므로 필요한 필드) 
	int dege_size = 0;;

	graph() { //생성자 (정점개수랑 인접행렬 초기화
		vertex_size = 0;
		edge_matrix = NULL;
	}
	void insert_vertex(int vertex_id) { //정점추가(고유번호) 
										//이 고유번호를 갖는 정점이 이미 정점리스트에 존재하는지 확인
		if (vertex_list.find_vertex(vertex_id) != NULL) return;

		//없다면
		//이 고유번호를 갖는 새 정점 생성
		vertex* new_vertex = new vertex(vertex_id);

		//크기가 (기존정점개수+1)*(기존점정개수+1)인 새 인접행렬 생성
		edge*** new_matrix = new edge * *[vertex_size + 1];
		for (int i = 0; i < vertex_size + 1; i++)
			new_matrix[i] = new edge *[vertex_size + 1]; //한행에 총정점개수만한 edge*타입의 배열 공간할당 

														 //기존에 있던 내용 복사
		for (int i = 0; i < vertex_size; i++)
			for (int j = 0; j < vertex_size; j++)
				new_matrix[i][j] = edge_matrix[i][j];
		//새롭게 추가된 공간(행은 0~v, 열은 v, 열이 0~v, 행은 v인 부분)은 null
		for (int i = 0; i < vertex_size + 1; i++)
			new_matrix[i][vertex_size] = new_matrix[vertex_size][i] = NULL;

		//멤버변수 edge_matrix는 기존의 인접행렬의 0,0의 주소를 가지고 있음.-> 기존 인접행렬 할당해제 
		for (int i = 0; i < vertex_size; i++)
			delete[] edge_matrix[i];
		delete[] edge_matrix;

		//새로 만든 입접행렬을 edge_matrix에 대입. 
		edge_matrix = new_matrix;
		//새 정접을 정접리스트에 추가
		vertex_list.insert_back(new_vertex);
		vertex_size++; //총정점개수증가. 
		return;
	}

	int erase_vertex(int vertex_id) { //정점삭제 
									   //이 고유번호를 가진 정점이 있는지 확인
		vertex* del_vertex = vertex_list.find_vertex(vertex_id);
		if (del_vertex == NULL) {
			return 0;
		}; //없다면 함수종료. 

		int del_idx = del_vertex->matrix_id; //삭제할 정점의 행렬번호

		edge*** new_matrix = new edge * *[vertex_size - 1]; //크기가 기존정점개수-1인 새 edge matrix 생성 
		for (int i = 0; i < vertex_size - 1; i++)
			new_matrix[i] = new edge *[vertex_size + -1];

		//새 행렬에 삭제할 정점에 대한 거 빼고 기존내용복사 
		for (int i = 0; i < vertex_size - 1; i++) {
			for (int j = 0; j < vertex_size - 1; j++) {
				if (i < del_idx && j < del_idx) new_matrix[i][j] = edge_matrix[i][j];
				else if (i < del_idx) new_matrix[i][j] = edge_matrix[i][j + 1];
				else if (j < del_idx)new_matrix[i][j] = edge_matrix[i + 1][j];
				else new_matrix[i][j] = edge_matrix[i + 1][j + 1];
			}
		}
		for (int i = 0; i < vertex_size; i++)
			if (edge_matrix[del_idx][i] != NULL)
				edge_list.remove(edge_matrix[del_idx][i]);

		for (int i = 0; i < vertex_size; i++)
			delete[] edge_matrix[i];
		delete[] edge_matrix;


		edge_matrix = new_matrix;
		vertex_list.remove(del_vertex);
		vertex_size--;
		return 1;
	}

	void insertEdge(int src_vertex_id, int dst_vertex_id,string m) {//간선 삽입. 
		vertex* src_vertex = vertex_list.find_vertex(src_vertex_id);
		vertex* dst_vertex = vertex_list.find_vertex(dst_vertex_id);
		if (src_vertex == NULL || dst_vertex == NULL) {
			cout << -1 << endl;
			return;
		}
		int src_id = src_vertex->matrix_id;
		int dst_id = dst_vertex->matrix_id;
		if (edge_matrix[src_id][dst_id] != NULL || edge_matrix[dst_id][src_id] != NULL) {
				cout << -1 << endl;
				return;
			}

		edge* new_edge = new edge(src_vertex, dst_vertex,m); //새 간선 생성.
		edge_list.insert_back(new_edge);
		edge_matrix[src_id][dst_id] = edge_matrix[dst_id][src_id] = new_edge;
		dege_size++;
		return;
	}

	void eraseEdge(int src_vertex_id, int dst_vertex_id) {
		vertex* src_vertex = vertex_list.find_vertex(src_vertex_id);
		vertex* dst_vertex = vertex_list.find_vertex(dst_vertex_id);

		if (src_vertex == NULL || dst_vertex == NULL) return;
		int src_id = src_vertex->matrix_id;
		int dst_id = dst_vertex->matrix_id;
		if (edge_matrix[src_id][dst_id] == NULL || edge_matrix[dst_id][src_id] == NULL) {
			cout << "None" << endl;
			return; //간선이 존재하지 않음
		}
		edge_list.remove(edge_matrix[src_id][dst_id]);
		edge_matrix[src_id][dst_id] = edge_matrix[dst_id][src_id] = NULL;
		dege_size--;
		return;
	}

	void incidentEdges(int vertex_id) {
		if (vertex_list.find_vertex(vertex_id) == NULL) return;
		vertex* _vertex = vertex_list.find_vertex(vertex_id);
		int count = 0;
		int m_num = _vertex->matrix_id;
		for (int i = 0; i < vertex_size; i++) {
			if (edge_matrix[m_num][i] != NULL) {
				count++;
			}
		}
		cout << count << endl;
	}
	void isAdjacentTo(int src_vertex_id, int dst_vertex_id) {
		vertex* src_vertex = vertex_list.find_vertex(src_vertex_id);
		vertex* dst_vertex = vertex_list.find_vertex(dst_vertex_id);
		if (src_vertex == NULL || dst_vertex == NULL) {
			cout << -1 << endl;
			return;
		};
		int src_id = src_vertex->matrix_id;
		int dst_id = dst_vertex->matrix_id;
		if (edge_matrix[src_id][dst_id] != NULL) {
			cout << 1 << endl;
			return;
		}
		cout << 0 << endl;
		return ;
	}
	int vLength() {
		int c = 0;
		edge *e = edge_list.header;
		while (e->next !=edge_list.trailer) {
			c++;
			e = e->next;
		}
		return c;
	}
	void printList() {
		edge *e = edge_list.header;
		while (e != edge_list.trailer) {
			cout << e->message << " ";
			e = e->next;
		}
		return;
	}
};

int main() {
	int t, n,k;
	cin >> t >> n>>k;
	string m;
	graph g;
	int x,y;
	for (int i = 0; i < t; i++) {
		cin >> x;
		g.insert_vertex(x);
	}
	for (int i = 0; i < n; i++) {
		cin >> x>> y>>m;
		g.insertEdge(x,y,m);
	}
	cout << g.vertex_size << " " << g.vLength() << endl;
	for (int i = 0; i < k; i++) {
		cin >> x;
		if (g.erase_vertex(x) == 0) {
			cout << -1 << endl;
		}
		else {
		cout << g.vLength();
		g.printList();
		cout << endl;
		}

	}
}