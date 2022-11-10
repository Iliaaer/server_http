# server_http
'''bash
mkdir build 
cd build 
cmake ..
make 
./server 
'''

Отпарвка Post
'''bash
curl -XPOST -H "Content-type: application/json" -d '{"coords": {"x": 448.4682917572079, "y": 488.43206404171633, "z": 80}, "picture": "", "speed": 30, "speedSearch": 10, "type": "Техника"}' 'http://192.168.133.141:8080/post_coords'
'''

Посмотреть Get запрос
Зайти на сайт '''bash http://192.168.133.141:8080/hi'''
