import 'package:get/get.dart';
import 'package:http/http.dart' as http;

class AppController extends GetxController{

final String nodeMCUIP = '192.168.96.1';

Future<void> sendCommandToNodeMCU(String command) async {
  try {
    final response = await http.get(Uri.http('$nodeMCUIP', '/command', {'cmd': command}));
    // handle the response here
  } catch (e) {
    print('Error sending command to NodeMCU: $e');
  }
}

}