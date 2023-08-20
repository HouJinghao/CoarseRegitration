//#include <iostream>
//#include <pcl/io/pcd_io.h>
//#include <pcl/point_types.h>
//#include <pcl/console/time.h>   
//#include <pcl/registration/ia_kfpcs.h> //K4PCS�㷨ͷ�ļ�
//#include <pcl/visualization/pcl_visualizer.h>
//#include <boost/thread/thread.hpp>
//
//using namespace std;
//
//int
//main(int argc, char** argv)
//{
//	pcl::console::TicToc time;
//	//----------------------------��ȡ��������----------------------------------
//	pcl::PointCloud<pcl::PointXYZ>::Ptr target(new pcl::PointCloud<pcl::PointXYZ>);
//	if (pcl::io::loadPCDFile<pcl::PointXYZ>("Cam03_Cloud.pcd", *target) == -1)// ����Ŀ�����
//	{
//		PCL_ERROR("��ȡĿ�����ʧ�� \n");
//		return (-1);
//	}
//	cout << "��Ŀ������ж�ȡ " << target->size() << " ����" << endl;
//
//	pcl::PointCloud<pcl::PointXYZ>::Ptr source(new pcl::PointCloud<pcl::PointXYZ>);
//	if (pcl::io::loadPCDFile<pcl::PointXYZ>("Cam04_Cloud.pcd", *source) == -1)// ����Դ����
//	{
//		PCL_ERROR("��ȡԴ�����ʧ�� \n");
//		return (-1);
//	}
//	cout << "��Դ�����ж�ȡ " << source->size() << " ����" << endl;
//	time.tic();
//	//--------------------------K4PCS�㷨������׼------------------------------
//	pcl::registration::KFPCSInitialAlignment<pcl::PointXYZ, pcl::PointXYZ> kfpcs;
//	kfpcs.setInputSource(source);  // Դ����
//	kfpcs.setInputTarget(target);  // Ŀ�����
//	kfpcs.setApproxOverlap(0.7);   // Դ��Ŀ��֮��Ľ����ص���
//	kfpcs.setLambda(0.5);          // ƽ�ƾ���ļ�Ȩϵ����(��ʱ��֪���Ǹ�ʲô�õ�)
//	kfpcs.setDelta(0.002, false);  // ��׼��Դ���ƺ�Ŀ�����֮��ľ���
//	kfpcs.setNumberOfThreads(6);   // OpenMP���̼߳��ٵ��߳���
//	kfpcs.setNumberOfSamples(200); // ��׼ʱҪʹ�õ��������������
//	//kfpcs.setMaxComputationTime(1000);//������ʱ��(����Ϊ��λ)��
//	pcl::PointCloud<pcl::PointXYZ>::Ptr kpcs(new pcl::PointCloud<pcl::PointXYZ>);
//	kfpcs.align(*kpcs);
//
//	cout << "KFPCS��׼��ʱ�� " << time.toc() << " ms" << endl;
//	cout << "�任����\n" << kfpcs.getFinalTransformation() << endl;
//	// ʹ�ô����ı任��Ϊ�����Դ���ƽ��б任
//	pcl::transformPointCloud(*source, *kpcs, kfpcs.getFinalTransformation());
//	// ����ת�����Դ������Ϊ���յı任���
//	//  pcl::io::savePCDFileASCII ("transformed.pcd", *kpcs);
//	//--------------------------���ӻ����----------------------------------
//	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("��׼���"));
//	int v1 = 0;
//	int v2 = 1;
//	viewer->createViewPort(0, 0, 0.5, 1, v1);
//	viewer->createViewPort(0.5, 0, 1, 1, v2);
//	viewer->setBackgroundColor(0, 0, 0, v1);
//	viewer->setBackgroundColor(0.05, 0, 0, v2);
//	viewer->setWindowName("4PCS�㷨ʵ�ֵ��ƴ���׼");
//	viewer->addText("Raw point clouds", 10, 10, "v1_text", v1);
//	viewer->addText("Registed point clouds", 10, 10, "v2_text", v2);
//	//ԭʼ������ɫ
//	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> src_h(source, 0, 255, 0);
//	//Ŀ�������ɫ
//	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> tgt_h(target, 0, 0, 255);
//	//ת�����Դ���ƺ�ɫ
//	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> transe(kpcs, 255, 0, 0);
//	//viewer->setBackgroundColor(255, 255, 255);
//	viewer->addPointCloud(source, src_h, "source cloud", v1);
//	viewer->addPointCloud(target, tgt_h, "target cloud", v1);
//	viewer->addPointCloud(target, tgt_h, "target cloud1", v2);
//	viewer->addPointCloud(kpcs, transe, "pcs cloud", v2);
//	//�������ϵ
//	//viewer->addCoordinateSystem(0.1);
//	//viewer->initCameraParameters();
//	while (!viewer->wasStopped())
//	{
//		viewer->spinOnce(100);
//		boost::this_thread::sleep(boost::posix_time::microseconds(10000));
//	}
//
//
//	return (0);
//}
//
