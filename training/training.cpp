/* training.cpp */
#include <QtGui>
#include "training.h"

 MainWindow::MainWindow(void)
{
	startAction = new QAction(tr("&Start"), this);				/* 创建打开动作 */
	startAction->setStatusTip(tr("Start training!"));				/* 设置状态提示 */

	stopAction = new QAction(tr("&Stop"), this);				/* 创建关闭动作 */
	stopAction->setStatusTip(tr("Stop training!"));				/* 设置状态提示 */

	helpAction = new QAction(tr("&Help"), this);				/* 创建关于动作 */
	helpAction->setStatusTip(tr("Help"));						/* 设置状态提示 */

	fileMenu = menuBar()->addMenu(tr("&File"));				/* 创建file菜单 */
	fileMenu->addAction(openAction);
	fileMenu->addAction(closeAction);

	helpMenu = menuBar()->addMenu(tr("&Help"));				/* 创建help菜单 */
	helpMenu->addAction(aboutAction);

	fileToolBar = addToolBar(tr("&File"));
	fileToolBar->addAction(openAction);
	fileToolBar->addAction(closeAction);
	fileToolBar->addAction(aboutAction);

	statusLabel = new QLabel;
	statusLabel->setMinimumSize(statusLabel->sizeHint());
	statusLabel->setAlignment(Qt::AlignHCenter);

	statusBar()->addWidget(statusLabel);
}

MainWindow::~MainWindow(void)
{
}

