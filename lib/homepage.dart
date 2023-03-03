import 'package:demo/controller.dart';
import 'package:flutter/material.dart';
import 'package:flutter/src/widgets/framework.dart';
import 'package:flutter/src/widgets/placeholder.dart';
import 'package:get/get.dart';

class HomePage extends StatelessWidget {
  const HomePage({super.key});

  @override
  Widget build(BuildContext context) {
    AppController appController = Get.put(AppController());
    return Scaffold(
        body: SafeArea(
      child: Center(
          child: ElevatedButton(
        onPressed: () {
          appController.sendCommandToNodeMCU("hello");
        },
        child: Text("button"),
      ),),
    ),);
  }
}
