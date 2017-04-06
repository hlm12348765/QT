/* training.h */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>					/* 包含对QMainWindow的定义 */

class QAction;
class QMenu;
class QToolBar;
class QLabel;

class MainWindow : public QMainWindow		/* 声明MainWindow为QMainWindow的子类*/
{
	Q_OBJECT;
public:
	MainWindow(void);
	~MainWindow(void);

private:
	QMenu   *fileMenu;					/* 文件菜单 */
	QMenu   *helpMenu;				/* 帮助菜单 */

	QToolBar *fileToolBar;				/* 工具栏 */

	QAction *startAction;					/* 开始动作 */
	QAction *stopAction;					/* 结束动作 */
	QAction *helpAction;				/* 帮助动作 */

	QLabel  *statusLabel;
};

#endif
