#include<windows.h>
#include<gl/glut.h>
#include<math.h>

//Tema TR   : Morocco Mall
//Ketua     : Bambang Sugiarto - 672019044
//Anggota   : Muhamad Makhasinul Maarif -672019067
//            Teguh Riyadi - 672019154


void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void mouseMotion(int, int);
void ukuran(int, int);

int is_depth;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

float PI = 3.14;

float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;

void tabung(int radius, int jumlah_titik, int x_tengah, int z_tengah, int y_bawah, int y_alas, int y_tinggi, int tutupatap, int r, int g, int b, int pola) {
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float z = z_tengah + radius * sin(sudut);
        glColor3ub(r, g, b);
        glVertex3d(x, y_tinggi, z);
        glVertex3d(x, y_bawah, z);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float z = z_tengah + radius * sin(sudut);
        glColor3ub(217, 248, 255);
        glVertex3d(x, tutupatap, z);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float z = z_tengah + radius * sin(sudut);
        glColor3ub(17, 160, 191);
        glVertex3d(x, y_alas, z);
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 700);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("MOROCCO MALL");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void tampil(void)
{
    if (is_depth) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glLineWidth(3.0);
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glTranslatef(xmov, ymov, zmov);
    glPushMatrix();

    tabung(10, 180, 64, -6, -8, -5, 8, 8, 17, 160, 191, 20);

    //LANTAI BAWAH
    glBegin(GL_QUADS);
    glColor3ub(5, 107, 0);
    glVertex3f(-140, -9, -100);
    glVertex3f(-140, -9, 100);
    glVertex3f(120, -9, 100);
    glVertex3f(120, -9, -100);
    glEnd();
    //LANTAI BAWAH 2
    glBegin(GL_QUADS);
    glColor3ub(82, 60, 43);
    glVertex3f(-104, -8, -35);
    glVertex3f(-104, -8, 19);
    glVertex3f(84, -8, 19);
    glVertex3f(84, -8, -35);
    glEnd();

    //TEMBOK DEPAN
    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-98, -8, 12);
    glVertex3f(-98, 8, 12);
    glVertex3f(-62, 8, 13);
    glVertex3f(-62, -8, 13);
    glEnd();
    glBegin(GL_QUADS);//tembok double
    glColor3ub(196, 192, 188);
    glVertex3f(-98.3, -8, 13.5);
    glVertex3f(-98.3, 10, 15);
    glVertex3f(-30, 10, 17);
    glVertex3f(-30, -8, 15.5);
    glEnd();





    glBegin(GL_QUADS);//tembok double pinggir belakang
    glColor3ub(196, 192, 188);
    glVertex3f(-97.1, -8, -27.5);
    glVertex3f(-97.1, 10, -29);
    glVertex3f(-97.1, 10, -25);
    glVertex3f(-97.1, -8, -25);
    glEnd();
    glBegin(GL_QUADS);//tembok double pinggir depan
    glColor3ub(196, 192, 188);
    glVertex3f(-98.1, -8, 13.5);
    glVertex3f(-98.1, 10, 15);
    glVertex3f(-98.1, 10, 11);
    glVertex3f(-98.1, -8, 11);
    glEnd();

    glBegin(GL_QUADS);//tembok double
    glColor3ub(196, 192, 188);
    glVertex3f(-98.3, 10, 11.5);
    glVertex3f(-98.3, 10, 15);
    glVertex3f(-30, 10, 17);
    glVertex3f(-30, 10, 12.5);
    glEnd();
    glBegin(GL_QUADS);//tembok double
    glColor3ub(196, 192, 188);
    glVertex3f(-98.3, 10, 11.5);
    glVertex3f(-98.3, 8, 11.5);
    glVertex3f(-30, 8, 12.5);
    glVertex3f(-30, 10, 12.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(196, 192, 188);
    glVertex3f(-62, -8, 12);
    glVertex3f(-62, 8, 12);
    glVertex3f(-62, 8, 13);
    glVertex3f(-62, -8, 13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-62, -8, 12);
    glVertex3f(-62, 8, 12);
    glVertex3f(-30, 8, 14.5);
    glVertex3f(-30, -8, 14.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-30, -8, 13);
    glVertex3f(-30, 8, 13);
    glVertex3f(-16, 8, 13);
    glVertex3f(-16, -8, 13);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-16, -8, 14.5);
    glVertex3f(-16, 8, 14.5);
    glVertex3f(-16, 8, 13);
    glVertex3f(-16, -8, 13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-16, -8, 13);
    glVertex3f(-16, 8, 13);
    glVertex3f(72, 8, 9);
    glVertex3f(72, -8, 9);
    glEnd();
    glBegin(GL_QUADS);//tembok double
    glColor3ub(196, 192, 188);
    glVertex3f(-30, -8, 15.5);
    glVertex3f(-30, 10, 17);
    glVertex3f(72, 10, 12);
    glVertex3f(72, -8, 10.5);
    glEnd();
    glBegin(GL_QUADS);//tembok double pinggir
    glColor3ub(196, 192, 188);
    glVertex3f(72, -8, 10.5);
    glVertex3f(72, 10, 12);
    glVertex3f(72, 10, 8);
    glVertex3f(72, -8, 8);
    glEnd();
    glBegin(GL_QUADS);//tembok double
    glColor3ub(196, 192, 188);
    glVertex3f(-30, 10, 12.5);
    glVertex3f(-30, 10, 17);
    glVertex3f(72, 10, 12);
    glVertex3f(72, 10, 8);
    glEnd();
    glBegin(GL_QUADS);//tembok double
    glColor3ub(196, 192, 188);
    glVertex3f(-30, 10, 12.5);
    glVertex3f(-30, 8, 12.5);
    glVertex3f(72, 8, 8);
    glVertex3f(72, 10, 8);
    glEnd();
    //--------------------------------
    //Lengkung DEPAN
    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(72.39823, -8, 9.50509);
    glVertex3f(72.39823, 8, 9.50509);
    glVertex3f(72.39823, 8, 8.08384);
    glVertex3f(72.39823, -8, 8.08384);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(72.39823, -8, 8.08384);
    glVertex3f(72.39823, 8, 8.08384);
    glVertex3f(72.39823, 8, 8.08384);
    glVertex3f(72.39823, -8, 8.08384);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(72.39823, -8, 8.08384);
    glVertex3f(72.39823, 8, 8.08384);
    glVertex3f(72, 8, 4);
    glVertex3f(72, -8, 4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(72, -8, 4);
    glVertex3f(72, 8, 4);
    glVertex3f(71.0281, 8, 2.66935);
    glVertex3f(71.0281, -8, 2.66935);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(71.0281, -8, 2.66935);
    glVertex3f(71.0281, 8, 2.66935);
    glVertex3f(69.33892, 8, 1.17725);
    glVertex3f(69.33892, -8, 1.17725);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(69.33892, -8, 1.17725);
    glVertex3f(69.33892, 8, 1.17725);
    glVertex3f(66.45098, 8, -0.52917);
    glVertex3f(66.45098, -8, -0.52917);
    glEnd();
    //------------------------------------ layar
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(71.29516, -4, -19.5503);
    glVertex3f(71.29516, 4, -19.5503);
    glVertex3f(72.77152, 4, -18.30173);
    glVertex3f(72.77152, -4, -18.30173);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(72.77152, -4, -18.30173);
    glVertex3f(72.77152, 4, -18.30173);
    glVertex3f(74.09781, 4, -16.76603);
    glVertex3f(74.09781, -4, -16.76603);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(74.09781, -4, -16.76603);
    glVertex3f(74.09781, 4, -16.76603);
    glVertex3f(75.14487, 4, -14.7417);
    glVertex3f(75.14487, -4, -14.7417);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(75.14487, -4, -14.7417);
    glVertex3f(75.14487, 4, -14.7417);
    glVertex3f(75.35429, 4, -11.87972);
    glVertex3f(75.35429, -4, -11.87972);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(75.35429, -4, -11.87972);
    glVertex3f(75.35429, 4, -11.87972);
    glVertex3f(74.55154, 4, -9.71578);
    glVertex3f(74.55154, -4, -9.71578);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(74.55154, -4, -9.71578);
    glVertex3f(74.55154, 4, -9.71578);
    glVertex3f(72.59701, 4, -8.38949);
    glVertex3f(72.59701, -4, -8.38949);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(72.59701, -4, -8.38949);
    glVertex3f(72.59701, 4, -8.38949);
    glVertex3f(67.37855, 4, -7.83174);
    glVertex3f(67.37855, -4, -7.83174);
    glEnd();


    //Lengkung belakang
    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(71.29516, -8, -19.5503);
    glVertex3f(71.29516, 8, -19.5503);
    glVertex3f(72.77152, 8, -18.30173);
    glVertex3f(72.77152, -8, -18.30173);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(72.77152, -8, -18.30173);
    glVertex3f(72.77152, 8, -18.30173);
    glVertex3f(74.09781, 8, -16.76603);
    glVertex3f(74.09781, -8, -16.76603);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(74.09781, -8, -16.76603);
    glVertex3f(74.09781, 8, -16.76603);
    glVertex3f(75.14487, 8, -14.7417);
    glVertex3f(75.14487, -8, -14.7417);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(75.14487, -8, -14.7417);
    glVertex3f(75.14487, 8, -14.7417);
    glVertex3f(75.35429, 8, -11.87972);
    glVertex3f(75.35429, -8, -11.87972);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(75.35429, -8, -11.87972);
    glVertex3f(75.35429, 8, -11.87972);
    glVertex3f(74.55154, 8, -9.71578);
    glVertex3f(74.55154, -8, -9.71578);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(74.55154, -8, -9.71578);
    glVertex3f(74.55154, 8, -9.71578);
    glVertex3f(72.59701, 8, -8.38949);
    glVertex3f(72.59701, -8, -8.38949);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(72.59701, -8, -8.38949);
    glVertex3f(72.59701, 8, -8.38949);
    glVertex3f(67.37855, 8, -7.83174);
    glVertex3f(67.37855, -8, -7.83174);
    glEnd();





    //Tembok belakang dari kanan ke kiri
    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(60, -8, -21);
    glVertex3f(60, 8, -21);
    glVertex3f(71.29516, 8, -19.5503);
    glVertex3f(71.29516, -8, -19.5503);
    glEnd();
    glBegin(GL_QUADS);//tembok double
    glColor3ub(196, 192, 188);
    glVertex3f(60, -8, -22.5);
    glVertex3f(60, 10, -24);
    glVertex3f(71.29516, 10, -22);
    glVertex3f(71.29516, -8, -20.5);
    glEnd();

    // jendela tembok belakang dari kanan
    glBegin(GL_QUADS);//jendela 1
    glColor3ub(54, 85, 224);
    glVertex3f(60, 9, -23);
    glVertex3f(60, 9, -24.5);
    glVertex3f(65.29516, 9, -23.5);
    glVertex3f(65.29516, 9, -22);
    glEnd();
    glBegin(GL_QUADS);// jendela 1
    glColor3ub(54, 85, 224);
    glVertex3f(60, -5, -22.5);
    glVertex3f(60, -5, -23.5);
    glVertex3f(65.29516, -5, -22);
    glVertex3f(65.29516, -5, -21);
    glEnd();
    glBegin(GL_QUADS);// jendela 1
    glColor3ub(54, 85, 224);
    glVertex3f(60, 9, -23.5);
    glVertex3f(60, 9, -24.5);
    glVertex3f(60, -5, -23.5);
    glVertex3f(60, -5, -22);
    glEnd();
    glBegin(GL_QUADS);// jendela 1
    glColor3ub(54, 85, 224);
    glVertex3f(65.29516, 9, -21.5);
    glVertex3f(65.29516, 9, -23.5);
    glVertex3f(65.29516, -5, -22.5);
    glVertex3f(65.29516, -5, -20.5);
    glEnd();
    glBegin(GL_QUADS);// kaca
    glColor3ub(255, 255, 255);
    glVertex3f(60, -5, -23.5);
    glVertex3f(60, 9, -24.5);
    glVertex3f(65.29516, 9, -23.5);
    glVertex3f(65.29516, -5, -22.5);
    glEnd();








    glBegin(GL_QUADS);//tembok double
    glColor3ub(54, 85, 224);
    glVertex3f(60, 9, -23);
    glVertex3f(60, 9, -24.5);
    glVertex3f(65.29516, 9, -23);
    glVertex3f(65.29516, 9, -22);
    glEnd();


    glBegin(GL_QUADS);//tembok double
    glColor3ub(196, 192, 188);
    glVertex3f(71.29516, -8, -19.5503);
    glVertex3f(71.29516, 10, -19);
    glVertex3f(71.29516, 10, -22);
    glVertex3f(71.29516, -8, -20.5);
    glEnd();



    glBegin(GL_QUADS);//tembok double
    glColor3ub(196, 192, 188);
    glVertex3f(60, 10, -20.5);
    glVertex3f(60, 10, -24);
    glVertex3f(71.29516, 10, -22);
    glVertex3f(71.29516, 10, -19);
    glEnd();
    glBegin(GL_QUADS);//tembok double
    glColor3ub(196, 192, 188);
    glVertex3f(60, 10, -20.5);
    glVertex3f(60, 8, -20.5);
    glVertex3f(71.29516, 8, -19);
    glVertex3f(71.29516, 10, -19);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(22, -8, -25);
    glVertex3f(22, 8, -25);
    glVertex3f(60, 8, -21);
    glVertex3f(60, -8, -21);
    glEnd();



    glBegin(GL_QUADS);//tembok dobel
    glColor3ub(196, 192, 188);
    glVertex3f(22, -8, -26.5);
    glVertex3f(22, 10, -28);
    glVertex3f(60, 10, -24);
    glVertex3f(60, -8, -22.5);
    glEnd();

    //jendela 2

    glBegin(GL_QUADS);//jendela atas
    glColor3ub(54, 85, 224);
    glVertex3f(58, 9, -24.5);
    glVertex3f(58, 9, -25);
    glVertex3f(52.8, 9, -25.8);
    glVertex3f(52.8, 9, -23.5);
    glEnd();

    glBegin(GL_QUADS);//jendela bawah
    glColor3ub(54, 85, 224);
    glVertex3f(58, -5, -23);
    glVertex3f(58, -5, -23.8);
    glVertex3f(52.8, -5, -24.5);
    glVertex3f(52.8, -5, -23.5);
    glEnd();

    glBegin(GL_QUADS);//jendela kanan
    glColor3ub(54, 85, 224);
    glVertex3f(58, 9, -23);
    glVertex3f(58, 9, -25);
    glVertex3f(58, -5, -24);
    glVertex3f(58, -5, -23.5);
    glEnd();

    glBegin(GL_QUADS);//jendela kiri
    glColor3ub(54, 85, 224);
    glVertex3f(52.8, 9, -24);
    glVertex3f(52.8, 9, -25.8);
    glVertex3f(52.8, -5, -24.6);
    glVertex3f(52.8, -5, -23.5);
    glEnd();

    glBegin(GL_QUADS);//Kaca jendela 2
    glColor3ub(255, 255, 255);
    glVertex3f(58, 9, -25);
    glVertex3f(58, -5, -24);
    glVertex3f(52.8, -5, -24.6);
    glVertex3f(52.8, 9, -25.8);
    glEnd();

    //jendela 3

    glBegin(GL_QUADS);//jendela atas
    glColor3ub(54, 85, 224);
    glVertex3f(50.8, 9, -24.5);
    glVertex3f(50.8, 9, -25.6);
    glVertex3f(45.6, 9, -26);
    glVertex3f(45.6, 9, -25);
    glEnd();

    glBegin(GL_QUADS);//jendela bawah
    glColor3ub(54, 85, 224);
    glVertex3f(50.8, -5, -23.5);
    glVertex3f(50.8, -5, -25.3);
    glVertex3f(45.6, -5, -25.8);
    glVertex3f(45.6, -5, -24);
    glEnd();

    glBegin(GL_QUADS);//jendela bawah
    glColor3ub(54, 85, 224);
    glVertex3f(50.8, 9, -23.5);
    glVertex3f(50.8, 9, -25.6);
    glVertex3f(50.8, -5, -24.8);
    glVertex3f(50.8, -5, -24);
    glEnd();

    glBegin(GL_QUADS);//jendela bawah
    glColor3ub(54, 85, 224);
    glVertex3f(45.6, 9, -25);
    glVertex3f(45.6, 9, -26);
    glVertex3f(45.6, -5, -25);
    glVertex3f(45.6, -5, -25.5);
    glEnd();

    glBegin(GL_QUADS);//kaca
    glColor3ub(255, 255, 255);
    glVertex3f(50.8, 9, -25.5);
    glVertex3f(50.8, -5, -25);
    glVertex3f(45.6, -5, -25.5);
    glVertex3f(45.6, 9, -26);
    glEnd();

    //jendela 4

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(43.6, 9, -25);
    glVertex3f(43.6, 9, -26.5);
    glVertex3f(38.8, 9, -27);
    glVertex3f(38.8, 9, -25);

    glEnd();

    glBegin(GL_QUADS);//jendela bawah 4
    glColor3ub(54, 85, 224);
    glVertex3f(43.6, -5, -25);
    glVertex3f(43.6, -5, -26);
    glVertex3f(38.8, -5, -26);
    glVertex3f(38.8, -5, -25);
    glEnd();

    glBegin(GL_QUADS);//jendela bawah
    glColor3ub(54, 85, 224);
    glVertex3f(43.6, 9, -25);
    glVertex3f(43.6, 9, -26.5);
    glVertex3f(43.6, -5, -26);
    glVertex3f(43.6, -5, -25);
    glEnd();

    glBegin(GL_QUADS);//jendela bawah
    glColor3ub(54, 85, 224);
    glVertex3f(38.8, 9, -25);
    glVertex3f(38.8, 9, -27);
    glVertex3f(38.8, -5, -26);
    glVertex3f(38.8, -5, -25);
    glEnd();

    glBegin(GL_QUADS);//kaca
    glColor3ub(255, 255, 255);
    glVertex3f(43.6, 9, -26.5);
    glVertex3f(38.8, 9, -27);
    glVertex3f(38.8, -5, -26);
    glVertex3f(43.6, -5, -26);
    glEnd();

    //jendela 5

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(36.8, 9, -26.2);
    glVertex3f(36.8, 9, -27);
    glVertex3f(31.6, 9, -27.6);
    glVertex3f(31.6, 9, -26.8);

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(36.8, -5, -25.5);
    glVertex3f(36.8, -5, -26.2);
    glVertex3f(31.6, -5, -26.5);
    glVertex3f(31.6, -5, -25.6);

    glBegin(GL_QUADS);//jendela bawah
    glColor3ub(54, 85, 224);
    glVertex3f(36.8, 9, -25);
    glVertex3f(36.8, 9, -27);
    glVertex3f(36.8, -5, -26);
    glVertex3f(36.8, -5, -25);
    glEnd();

    glBegin(GL_QUADS);//jendela bawah
    glColor3ub(54, 85, 224);
    glVertex3f(31.6, 9, -26);
    glVertex3f(31.6, 9, -27.5);
    glVertex3f(31.6, -5, -26.6);
    glVertex3f(31.6, -5, -25.8);
    glEnd();

    glBegin(GL_QUADS);//kaca
    glColor3ub(255, 255, 255);
    glVertex3f(36.8, 9, -27);
    glVertex3f(31.6, 9, -27.5);
    glVertex3f(31.6, -5, -26.5);
    glVertex3f(36.8, -5, -26);
    glEnd();

    //jendela 6

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(23.6, 9, -27.5);
    glVertex3f(23.6, 9, -28.5);
    glVertex3f(18.4, 9, -28.8);
    glVertex3f(18.4, 9, -28);

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(23.6, -5, -26.5);
    glVertex3f(23.6, -5, -27.4);
    glVertex3f(18.4, -5, -27.9);
    glVertex3f(18.4, -5, -27);

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(23.6, 9, -27.5);
    glVertex3f(23.6, 9, -28.5);
    glVertex3f(23.6, -5, -27.5);
    glVertex3f(23.6, -5, -26.5);

    glColor3ub(54, 85, 224);
    glVertex3f(18.4, 9, -27.5);
    glVertex3f(18.4, 9, -28.7);
    glVertex3f(18.4, -5, -27.7);
    glVertex3f(18.4, -5, -26.5);


    glBegin(GL_QUADS);//kaca
    glColor3ub(255, 255, 255);
    glVertex3f(23.6, 9, -28.5);
    glVertex3f(18.4, 9, -28.8);
    glVertex3f(18.4, -5, -27.8);
    glVertex3f(23.6, -5, -27.4);
    glEnd();

    //jendela 7

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(11.4, 9, -27.5);
    glVertex3f(11.4, 9, -28.6);
    glVertex3f(6.2, 9, -28.9);
    glVertex3f(6.2, 9, -28);

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(11.4, -5, -27);
    glVertex3f(11.4, -5, -27.6);
    glVertex3f(6.2, -5, -27.8);
    glVertex3f(6.2, -5, -27.5);

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(11.4, 9, -28);
    glVertex3f(11.4, 9, -28.8);
    glVertex3f(11.4, -5, -27.8);
    glVertex3f(11.4, -5, -27);

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(6.2, 9, -28);
    glVertex3f(6.2, 9, -28.8);
    glVertex3f(6.2, -5, -27.8);
    glVertex3f(6.2, -5, -27);

    glBegin(GL_QUADS);//kaca
    glColor3ub(255, 255, 255);
    glVertex3f(11.4, 9, -28.8);
    glVertex3f(6.2, 9, -28.8);
    glVertex3f(6.2, -5, -27.8);
    glVertex3f(11.4, -5, -27.7);
    glEnd();

    //jendela 8
    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(4.2, 9, -27.5);
    glVertex3f(4.2, 9, -28.7);
    glVertex3f(-1.0, 9, -29);
    glVertex3f(-1.0, 9, -28);

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(4.2, -5, -27.2);
    glVertex3f(4.2, -5, -27.8);
    glVertex3f(-1.0, -5, -28);
    glVertex3f(-1.0, -5, -27);

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(4.2, 9, -28);
    glVertex3f(4.2, 9, -28.9);
    glVertex3f(4.2, -5, -27.9);
    glVertex3f(4.2, -5, -27);

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(-1.0, 9, -28);
    glVertex3f(-1.0, 9, -29);
    glVertex3f(-1.0, -5, -28);
    glVertex3f(-1.0, -5, -27);


    glBegin(GL_QUADS);//kaca
    glColor3ub(255, 255, 255);
    glVertex3f(4.2, 9, -28.8);
    glVertex3f(-1.0, 9, -29);
    glVertex3f(-1.0, -5, -28);
    glVertex3f(4.2, -5, -27.9);
    glEnd();

    //jendela 9

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(-3.0, 9, -27.5);
    glVertex3f(-3.0, 9, -28.9);
    glVertex3f(-8.2, 9, -29.2);
    glVertex3f(-8.2, 9, -28);

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(-3.0, -5, -27.5);
    glVertex3f(-3.0, -5, -28.1);
    glVertex3f(-8.2, -5, -28.2);
    glVertex3f(-8.2, -5, -27.7);

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(-3.0, 9, -28.1);
    glVertex3f(-3.0, 9, -29.1);
    glVertex3f(-3.0, -5, -28);
    glVertex3f(-3.0, -5, -27.4);

    glBegin(GL_QUADS);//jendela atas 4
    glColor3ub(54, 85, 224);
    glVertex3f(-8.2, 9, -28.1);
    glVertex3f(-8.2, 9, -29.1);
    glVertex3f(-8.2, -5, -28);
    glVertex3f(-8.2, -5, -27.4);

    glBegin(GL_QUADS);//kaca
    glColor3ub(255, 255, 255);
    glVertex3f(-3.0, 9, -28.9);
    glVertex3f(-8.2, 9, -29.1);
    glVertex3f(-8.2, -5, -28.1);
    glVertex3f(-3.0, -5, -28);
    glEnd();




    glBegin(GL_QUADS);//tembok dobel
    glColor3ub(196, 192, 188);
    glVertex3f(22, 10, -24);
    glVertex3f(22, 10, -28);
    glVertex3f(60, 10, -24);
    glVertex3f(60, 10, -20.5);
    glEnd();
    glBegin(GL_QUADS);//tembok dobel
    glColor3ub(196, 192, 188);
    glVertex3f(22, 10, -24);
    glVertex3f(22, 8, -24);
    glVertex3f(60, 8, -20.5);
    glVertex3f(60, 10, -20.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-19, -8, -26);
    glVertex3f(-19, 8, -26);
    glVertex3f(22, 8, -25);
    glVertex3f(22, -8, -25);
    glEnd();
    glBegin(GL_QUADS);//tembok doubel
    glColor3ub(196, 192, 188);
    glVertex3f(-26, -8, -27.5);
    glVertex3f(-26, 10, -29);
    glVertex3f(22, 10, -28);
    glVertex3f(22, -8, -26.5);
    glEnd();
    glBegin(GL_QUADS);//tembok doubel
    glColor3ub(196, 192, 188);
    glVertex3f(-26, -8, -26);
    glVertex3f(-26, 10, -26);
    glVertex3f(-26, 10, -29);
    glVertex3f(-26, -8, -27.5);
    glEnd();
    glBegin(GL_QUADS);//tembok doubel
    glColor3ub(196, 192, 188);
    glVertex3f(-26, 10, -25);
    glVertex3f(-26, 10, -29);
    glVertex3f(22, 10, -28);
    glVertex3f(22, 10, -24);
    glEnd();
    glBegin(GL_QUADS);//tembok doubel
    glColor3ub(196, 192, 188);
    glVertex3f(-26, 10, -25);
    glVertex3f(-26, 8, -25);
    glVertex3f(22, 8, -24);
    glVertex3f(22, 10, -24);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-50, -8, -26);
    glVertex3f(-50, 8, -26);
    glVertex3f(-19, 8, -26);
    glVertex3f(-19, -8, -26);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-50, -8, -26);
    glVertex3f(-50, 8, -26);
    glVertex3f(-50, 8, -25);
    glVertex3f(-50, -8, -25);
    glEnd();
    glBegin(GL_QUADS);//tembok deobel
    glColor3ub(196, 192, 188);
    glVertex3f(-65, -8, -28.5);
    glVertex3f(-65, 10, -30);
    glVertex3f(-28, 10, -30);
    glVertex3f(-28, -8, -28.5);
    glEnd();
    glBegin(GL_QUADS);//tembok deobel samping
    glColor3ub(196, 192, 188);
    glVertex3f(-28, -8, -26);
    glVertex3f(-28, 10, -26);
    glVertex3f(-28, 10, -30);
    glVertex3f(-28, -8, -28.5);
    glEnd();
    glBegin(GL_QUADS);//tembok deobel samping
    glColor3ub(196, 192, 188);
    glVertex3f(-65, -8, -26);
    glVertex3f(-65, 10, -26);
    glVertex3f(-65, 10, -30);
    glVertex3f(-65, -8, -28.5);
    glEnd();
    glBegin(GL_QUADS);//tembok deobel
    glColor3ub(196, 192, 188);
    glVertex3f(-65, 10, -26);
    glVertex3f(-65, 10, -30);
    glVertex3f(-28, 10, -30);
    glVertex3f(-28, 10, -26);
    glEnd();
    glBegin(GL_QUADS);//tembok deobel
    glColor3ub(196, 192, 188);
    glVertex3f(-65, 10, -26);
    glVertex3f(-65, 8, -26);
    glVertex3f(-28, 8, -26);
    glVertex3f(-28, 10, -26);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-64, -8, -27);
    glVertex3f(-64, 8, -27);
    glVertex3f(-50, 8, -27);
    glVertex3f(-50, -8, -27);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-64, -8, -25);
    glVertex3f(-64, 8, -25);
    glVertex3f(-64, 8, -26);
    glVertex3f(-64, -8, -26);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-76, -8, -25);
    glVertex3f(-76, 8, -25);
    glVertex3f(-64, 8, -26);
    glVertex3f(-64, -8, -26);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-76, -8, -25);
    glVertex3f(-76, 8, -25);
    glVertex3f(-76, 8, -26);
    glVertex3f(-76, -8, -26);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-97, -8, -26);
    glVertex3f(-97, 8, -26);
    glVertex3f(-76, 8, -26);
    glVertex3f(-76, -8, -26);
    glEnd();

    glBegin(GL_QUADS);//tembok dobel
    glColor3ub(196, 192, 188);
    glVertex3f(-97, -8, -27.5);
    glVertex3f(-97, 10, -29);
    glVertex3f(-68, 10, -31);
    glVertex3f(-68, -8, -29.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-97, -8, -27.5);
    glVertex3f(-97, 10, -28.5);
    glVertex3f(-97, 10, -26);
    glVertex3f(-97, -8, -26);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-68, -8, -29.5);
    glVertex3f(-68, 10, -31);
    glVertex3f(-68, 10, -26);
    glVertex3f(-68, -8, -26);
    glEnd();
    glBegin(GL_QUADS);//tembok dobel
    glColor3ub(196, 192, 188);
    glVertex3f(-97, 10, -25.5);
    glVertex3f(-97, 10, -29);
    glVertex3f(-68, 10, -31);
    glVertex3f(-68, 10, -26);
    glEnd();

    glBegin(GL_QUADS);//tembok dobel
    glColor3ub(196, 192, 188);
    glVertex3f(-97, -8, -26);
    glVertex3f(-97, 10, -26);
    glVertex3f(-68, 10, -26);
    glVertex3f(-68, -8, -26);
    glEnd();
    //--------------------------
    //SAMPING KIRI

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-97, -8, -19);
    glVertex3f(-97, 8, -19);
    glVertex3f(-97, 8, -26);
    glVertex3f(-97, -8, -26);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-100, -8, -19);
    glVertex3f(-100, 8, -19);
    glVertex3f(-97, 8, -19);
    glVertex3f(-97, -8, -19);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-100, -8, 5);
    glVertex3f(-100, 8, 5);
    glVertex3f(-100, 8, -19);
    glVertex3f(-100, -8, -19);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-100, -8, 5);
    glVertex3f(-100, 8, 5);
    glVertex3f(-98, 8, 5);
    glVertex3f(-98, -8, 5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-98, -8, 12);
    glVertex3f(-98, 8, 12);
    glVertex3f(-98, 8, 5);
    glVertex3f(-98, -8, 5);
    glEnd();
    //-------------------------------
    //ATAP dari kiri
    glBegin(GL_QUADS);
    glColor3ub(115, 140, 145);
    glVertex3f(-100, 8, -19);
    glVertex3f(-97, 8, -21);
    glVertex3f(-98, 8, 5);
    glVertex3f(-100, 8, 5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(115, 140, 145);
    glVertex3f(-97, 8, -28);
    glVertex3f(-98.5, 8, 12);
    glVertex3f(-76, 8, 13);
    glVertex3f(-76, 8, -28);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(115, 140, 145);
    glVertex3f(-76, 8, -28);
    glVertex3f(-76, 8, 13);
    glVertex3f(-62, 8, 13);
    glVertex3f(-64, 8, -28);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(115, 140, 145);
    glVertex3f(-64, 8, -26);
    glVertex3f(-64, 8, 12);
    glVertex3f(-50, 8, 13.5);
    glVertex3f(-50, 8, -26);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(115, 140, 145);
    glVertex3f(-50, 8, -26);
    glVertex3f(-50, 8, 14);
    glVertex3f(-30, 8, 14);
    glVertex3f(-30, 8, -26);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(115, 140, 145);
    glVertex3f(-30, 8, -26);
    glVertex3f(-30, 8, 14);
    glVertex3f(-16, 8, 14);
    glVertex3f(-16, 8, -26);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(115, 140, 145);
    glVertex3f(-16, 8, -26);
    glVertex3f(-16, 8, 13);
    glVertex3f(22.5, 8, 11.5);
    glVertex3f(22.5, 8, -25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(115, 140, 145);
    glVertex3f(22, 7.8, -25);
    glVertex3f(22, 7.8, 11.5);
    glVertex3f(60, 7.8, 9.5);
    glVertex3f(60, 7.8, -21);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(115, 140, 145);
    glVertex3f(60, 7.8, 9.5);
    glVertex3f(60, 7.8, -21.2);
    glVertex3f(65.5, 7.8, -20.5);
    glVertex3f(65.5, 7.8, 9.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(115, 140, 145);
    glVertex3f(72.39823, 7.8, 9.50509);
    glVertex3f(72.39823, 7.8, 8.08384);
    glVertex3f(72.39823, 7.8, 8.08384);
    glVertex3f(72, 7.8, 4);
    glVertex3f(71.0281, 7.8, 2.66935);
    glVertex3f(69.33892, 7.8, 1.17725);
    glVertex3f(65.45752, 7.8, -0.99962);
    glVertex3f(65.5, 7.8, 9.49497);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(115, 140, 145);
    glVertex3f(71.29516, 7.8, -19.5503);
    glVertex3f(72.77152, 7.8, -18.30173);
    glVertex3f(74.09781, 7.8, -16.76603);
    glVertex3f(75.14487, 7.8, -14.7417);
    glVertex3f(75.35429, 7.8, -11.87972);
    glVertex3f(74.55154, 7.8, -9.71578);
    glVertex3f(72.59701, 7.8, -8.38949);
    glVertex3f(67.37855, 7.8, -7.83174);
    glVertex3f(63.5, 7.8, -5.5);
    glVertex3f(65.5, 7.8, -20.5);
    glEnd();

    //--------------------------------------------
    //lengkung kanan



    //ventilasi
    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-64.10, 10, -14.42);
    glVertex3f(-64.10, 8, -14.4);
    glVertex3f(-62.19, 8, -9.01);
    glVertex3f(-62.19, 10, -9.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-58.37728, 10, -17.44796);
    glVertex3f(-58.37728, 8, -17.44796);
    glVertex3f(-64.1068, 8, -14.42405);
    glVertex3f(-64.1068, 10, -14.42405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-50, 10, -20);
    glVertex3f(-50, 8, -20);
    glVertex3f(-58.37728, 8, -17.44796);
    glVertex3f(-58.37728, 10, -17.44796);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-45.16755, 10, -20.79018);
    glVertex3f(-45.16755, 8, -20.79018);
    glVertex3f(-50, 8, -20);
    glVertex3f(-50, 10, -20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-43.41686, 10, -15.53812);
    glVertex3f(-43.41686, 8, -15.53812);
    glVertex3f(-45.16755, 8, -20.79018);
    glVertex3f(-45.16755, 10, -20.79018);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-48.03231, 10, -14.42405);
    glVertex3f(-48.03231, 8, -14.42405);
    glVertex3f(-43.41686, 8, -15.53812);
    glVertex3f(-43.41686, 10, -15.53812);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-52.80691, 10, -12.67336);
    glVertex3f(-52.80691, 8, -12.67336);
    glVertex3f(-48.03231, 8, -14.42405);
    glVertex3f(-48.03231, 10, -14.42405);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-57.42236, 10, -11.08183);
    glVertex3f(-57.42236, 8, -11.08183);
    glVertex3f(-52.80691, 8, -12.67336);
    glVertex3f(-52.80691, 10, -12.67336);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-57.42236, 10, -11.08183);
    glVertex3f(-57.42236, 8, -11.08183);
    glVertex3f(-62.19696, 8, -9.01283);
    glVertex3f(-62.19696, 10, -9.01283);
    glEnd();

    //atap ventilasi 1

    glBegin(GL_POLYGON);
    glColor3ub(3, 136, 252);
    glVertex3f(-64.1068, 10, -14.42405);
    glVertex3f(-58.37728, 10, -17.44796);
    glVertex3f(-50, 10, -20);
    glVertex3f(-45.16755, 10, -20.79018);
    glVertex3f(-43.41686, 10, -15.53812);
    glVertex3f(-48.03231, 10, -14.42405);
    glVertex3f(-52.80691, 10, -12.67336);
    glVertex3f(-57.42236, 10, -11.08183);
    glVertex3f(-62.19696, 10, -9.01283);
    glEnd();

    //ventilasi 2 depan

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-54.39844, 10, 0.21806);
    glVertex3f(-54.39844, 8, 0.21806);
    glVertex3f(-49.29551, 8, 1.49098);
    glVertex3f(-49.29551, 10, 1.49098);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-49.29551, 10, 1.49098);
    glVertex3f(-49.29551, 8, 1.49098);
    glVertex3f(-45.52221, 8, 2.13325);
    glVertex3f(-45.52221, 10, 2.13325);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-45.52221, 10, 2.13325);
    glVertex3f(-45.52221, 8, 2.13325);
    glVertex3f(-41.34748, 8, 2.61495);
    glVertex3f(-41.34748, 10, 2.61495);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-41.34748, 10, 2.61495);
    glVertex3f(-41.34748, 8, 2.61495);
    glVertex3f(-37.09247, 8, 2.53466);
    glVertex3f(-37.09247, 10, 2.53466);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-37.09247, 10, 2.53466);
    glVertex3f(-37.09247, 8, 2.53466);
    glVertex3f(-33.15005, 8, 1.88497);
    glVertex3f(-33.15005, 10, 1.88497);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-33.15005, 10, 1.88497);
    glVertex3f(-33.15005, 8, 1.88497);
    glVertex3f(-32.51633, 8, 6.06712);
    glVertex3f(-32.51633, 10, 6.06712);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-32.51633, 10, 6.06712);
    glVertex3f(-32.51633, 8, 6.06712);
    glVertex3f(-37.09247, 8, 6.78967);
    glVertex3f(-37.09247, 10, 6.78967);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-37.09247, 10, 6.78967);
    glVertex3f(-37.09247, 8, 6.78967);
    glVertex3f(-41.66861, 8, 7.1108);
    glVertex3f(-41.66861, 10, 7.1108);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-41.66861, 10, 7.1108);
    glVertex3f(-41.66861, 8, 7.1108);
    glVertex3f(-46.89242, 8, 6.95311);
    glVertex3f(-46.89242, 10, 6.95311);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-46.89242, 10, 6.95311);
    glVertex3f(-46.89242, 8, 6.95311);
    glVertex3f(-50.65388, 8, 6.18547);
    glVertex3f(-50.65388, 10, 6.18547);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-50.65388, 10, 6.18547);
    glVertex3f(-50.65388, 8, 6.18547);
    glVertex3f(-55, 8, 5);
    glVertex3f(-55, 10, 5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-55, 10, 5);
    glVertex3f(-55, 8, 5);
    glVertex3f(-54.39844, 8, 0.21806);
    glVertex3f(-54.39844, 10, 0.21806);
    glEnd();

    //atap ventilasi 2

    glBegin(GL_POLYGON);
    glColor3ub(3, 136, 252);
    glVertex3f(-54.39844, 10, 0.21806);
    glVertex3f(-49.29551, 10, 1.49098);
    glVertex3f(-45.52221, 10, 2.13325);
    glVertex3f(-41.34748, 10, 2.61495);
    glVertex3f(-37.09247, 10, 2.53466);
    glVertex3f(-33.15005, 10, 1.88497);
    glVertex3f(-32.51633, 10, 6.06712);
    glVertex3f(-41.66861, 10, 7.1108);
    glVertex3f(-46.89242, 10, 6.95311);
    glVertex3f(-50.65388, 10, 6.18547);
    glVertex3f(-55, 10, 5);
    glVertex3f(-54.39844, 10, 0.21806);
    glEnd();

    //ventilasi  segitiga
    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);

    glVertex3f(-26.89549, 11, 4.98465);
    glVertex3f(-26.89549, 8, 4.98465);
    glVertex3f(-28.01501, 8, -0.27543);
    glVertex3f(-28.01501, 11, -0.27543);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-28.01501, 11, -0.27543);
    glVertex3f(-28.01501, 8, -0.27543);
    glVertex3f(-28.67882, 8, -5.71529);
    glVertex3f(-28.67882, 11, -5.71529);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-28.67882, 11, -5.71529);
    glVertex3f(-28.67882, 8, -5.71529);
    glVertex3f(-28.58301, 8, -10.35743);
    glVertex3f(-28.58301, 11, -10.35743);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-28.58301, 11, -10.35743);
    glVertex3f(-28.58301, 8, -10.35743);
    glVertex3f(-28.55144, 8, -14.7593);
    glVertex3f(-28.55144, 11, -14.7593);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);

    glVertex3f(-28.55144, 11, -14.7593);
    glVertex3f(-28.55144, 8, -14.7593);
    glVertex3f(-27.78716, 8, -19.21761);
    glVertex3f(-27.78716, 11, -19.21761);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-27.78716, 11, -19.21761);
    glVertex3f(-27.78716, 8, -19.21761);
    glVertex3f(-23.07408, 8, -18.19856);
    glVertex3f(-23.07408, 11, -18.19856);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-23.07408, 11, -18.19856);
    glVertex3f(-23.07408, 8, -18.19856);
    glVertex3f(-18.48839, 8, -16.67);
    glVertex3f(-18.48839, 11, -16.67);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-18.48839, 11, -16.67);
    glVertex3f(-18.48839, 8, -16.67);
    glVertex3f(-13.61594, 8, -14.28118);
    glVertex3f(-13.61594, 11, -14.28118);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);

    glVertex3f(-13.61594, 11, -14.28118);
    glVertex3f(-13.61594, 8, -14.28118);
    glVertex3f(-9.44439, 8, -11.44741);
    glVertex3f(-9.44439, 11, -11.44741);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-9.44439, 11, -11.44741);
    glVertex3f(-9.44439, 8, -11.44741);
    glVertex3f(-6.00512, 8, -7.75338);
    glVertex3f(-6.00512, 11, -7.75338);
    glEnd();

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);

    glVertex3f(-6.00512, 11, -7.75338);
    glVertex3f(-6.00512, 8, -7.75338);
    glVertex3f(-8.70301, 8, -3.96743);
    glVertex3f(-8.70301, 11, -3.96743);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-8.70301, 11, -3.96743);
    glVertex3f(-8.70301, 8, -3.96743);
    glVertex3f(-12.39501, 8, -1.12743);
    glVertex3f(-12.39501, 11, -1.12743);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-12.39501, 11, -1.12743);
    glVertex3f(-12.39501, 8, -1.12743);
    glVertex3f(-17.46935, 8, 1.80015);
    glVertex3f(-17.46935, 11, 1.80015);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-17.46935, 11, 1.80015);
    glVertex3f(-17.46935, 8, 1.80015);
    glVertex3f(-22.18242, 8, 3.45609);
    glVertex3f(-22.18242, 11, 3.45609);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-22.18242, 11, 3.45609);
    glVertex3f(-22.18242, 8, 3.45609);
    glVertex3f(-26.89549, 8, 4.98465);
    glVertex3f(-26.89549, 11, 4.98465);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(3, 136, 252);
    glVertex3f(-26.89549, 11, 4.98465);
    glVertex3f(-28.01501, 11, -0.27543);
    glVertex3f(-28.67882, 11, -5.71529);
    glVertex3f(-28.58301, 11, -10.35743);
    glVertex3f(-28.55144, 11, -14.7593);
    glVertex3f(-27.78716, 11, -19.21761);
    glVertex3f(-23.07408, 11, -18.19856);
    glVertex3f(-18.48839, 11, -16.67);
    glVertex3f(-13.61594, 11, -14.28118);
    glVertex3f(-9.44439, 11, -11.44741);
    glVertex3f(-6.00512, 11, -7.75338);
    glVertex3f(-8.70301, 11, -3.96743);
    glVertex3f(-12.39501, 11, -1.12743);
    glVertex3f(-17.46935, 11, 1.80015);
    glVertex3f(-22.18242, 11, 3.45609);
    glVertex3f(-26.89549, 11, 4.98465);
    glEnd();

    //ventilasi 3
    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(0.2352, 11, -12.29241);
    glVertex3f(0.2352, 8, -12.29241);
    glVertex3f(-1.95711, 8, -16.47774);
    glVertex3f(-1.95711, 11, -16.47774);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(-1.95711, 11, -16.47774);
    glVertex3f(-1.95711, 8, -16.47774);
    glVertex3f(0.93276, 8, -18.07215);
    glVertex3f(0.93276, 11, -18.07215);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(0.93276, 11, -18.07215);
    glVertex3f(0.93276, 8, -18.07215);
    glVertex3f(4.02193, 8, -19.36761);
    glVertex3f(4.02193, 11, -19.36761);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(4.02193, 11, -19.36761);
    glVertex3f(4.02193, 8, -19.36761);
    glVertex3f(7.69276, 8, -20.99671);
    glVertex3f(7.69276, 11, -20.99671);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(7.69276, 11, -20.99671);
    glVertex3f(7.69276, 8, -20.99671);
    glVertex3f(12.24948, 8, -21.45238);
    glVertex3f(12.24948, 11, -21.45238);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(12.24948, 11, -21.45238);
    glVertex3f(12.24948, 8, -21.45238);
    glVertex3f(17.254, 8, -21.68724);
    glVertex3f(17.254, 11, -21.68724);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(17.254, 11, -21.68724);
    glVertex3f(17.254, 8, -21.68724);
    glVertex3f(17.6214, 8, -17.89074);
    glVertex3f(17.6214, 11, -17.89074);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(17.6214, 11, -17.89074);
    glVertex3f(17.6214, 8, -17.89074);
    glVertex3f(13.0901, 8, -17.2784);
    glVertex3f(13.0901, 11, -17.2784);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(13.0901, 11, -17.2784);
    glVertex3f(13.0901, 8, -17.2784);
    glVertex3f(9.17113, 8, -16.54359);
    glVertex3f(9.17113, 11, -16.54359);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(9.17113, 11, -16.54359);
    glVertex3f(9.17113, 8, -16.54359);
    glVertex3f(6.2319, 8, -15.44138);
    glVertex3f(6.2319, 11, -15.44138);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(6.2319, 11, -15.44138);
    glVertex3f(6.2319, 8, -15.44138);
    glVertex3f(3.17021, 8, -13.97177);
    glVertex3f(3.17021, 11, -13.97177);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(3.17021, 11, -13.97177);
    glVertex3f(3.17021, 8, -13.97177);
    glVertex3f(0.2352, 8, -12.29241);
    glVertex3f(0.2352, 11, -12.29241);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(3, 136, 252);
    glVertex3f(-1.95711, 11, -16.47774);
    glVertex3f(0.93276, 11, -18.07215);
    glVertex3f(4.02193, 11, -19.36761);
    glVertex3f(7.69276, 11, -20.99671);
    glVertex3f(12.24948, 11, -21.45238);
    glVertex3f(17.254, 11, -21.68724);
    glVertex3f(17.6214, 11, -17.89074);
    glVertex3f(13.0901, 11, -17.2784);
    glVertex3f(9.17113, 11, -16.54359);
    glVertex3f(6.2319, 11, -15.44138);
    glVertex3f(3.17021, 11, -13.97177);
    glVertex3f(0.2352, 11, -12.29241);
    glVertex3f(-1.95711, 11, -16.47774);
    glEnd();

    //ventilasi 4
    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(0.32834, 11, -5.15422);
    glVertex3f(0.32834, 8, -5.15422);
    glVertex3f(4.12614, 8, -3.47436);
    glVertex3f(4.12614, 11, -3.47436);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(4.12614, 11, -3.47436);
    glVertex3f(4.12614, 8, -3.47436);
    glVertex3f(8.95401, 8, -2.9978);
    glVertex3f(8.95401, 11, -2.9978);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(8.95401, 11, -2.9978);
    glVertex3f(8.95401, 8, -2.9978);
    glVertex3f(12.8267, 8, -3.02433);
    glVertex3f(12.8267, 11, -3.02433);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(12.8267, 11, -3.02433);
    glVertex3f(12.8267, 8, -3.02433);
    glVertex3f(17.00463, 8, -3.42908);
    glVertex3f(17.00463, 11, -3.42908);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(17.00463, 11, -3.42908);
    glVertex3f(17.00463, 8, -3.42908);
    glVertex3f(18.07704, 8, 1.17594);
    glVertex3f(18.07704, 11, 1.17594);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(18.07704, 11, 1.17594);
    glVertex3f(18.07704, 8, 1.17594);
    glVertex3f(13.4106, 8, 1.89008);
    glVertex3f(13.4106, 11, 1.89008);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(13.4106, 11, 1.89008);
    glVertex3f(13.4106, 8, 1.89008);
    glVertex3f(8.95401, 8, 2.03384);
    glVertex3f(8.95401, 11, 2.03384);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(8.95401, 11, 2.03384);
    glVertex3f(8.95401, 8, 2.03384);
    glVertex3f(4.35365, 8, 1.4588);
    glVertex3f(4.35365, 11, 1.4588);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(4.35365, 11, 1.4588);
    glVertex3f(4.35365, 8, 1.4588);
    glVertex3f(0, 8, 0);
    glVertex3f(0, 11, 0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(0, 11, 0);
    glVertex3f(0, 8, 0);
    glVertex3f(0.32834, 8, -5.15422);
    glVertex3f(0.32834, 11, -5.15422);
    glEnd();

    //atap ventilasi 4
    glBegin(GL_POLYGON);
    glColor3ub(3, 136, 252);
    glVertex3f(0.32834, 8, -5.15422);
    glVertex3f(4.12614, 8, -3.47436);
    glVertex3f(8.95401, 8, -2.9978);
    glVertex3f(12.8267, 8, -3.02433);
    glVertex3f(17.00463, 8, -3.42908);
    glVertex3f(18.07704, 11, 1.17594);
    glVertex3f(13.4106, 11, 1.89008);
    glVertex3f(8.95401, 11, 2.03384);
    glVertex3f(4.35365, 11, 1.4588);
    glVertex3f(0, 11, 0);
    glEnd();

    //ventilasi 5
    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(25.64569, 11, -20.57949);
    glVertex3f(25.64569, 8, -20.57949);
    glVertex3f(31.90241, 8, -21.23123);
    glVertex3f(31.90241, 11, -21.23123);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(31.90241, 11, -21.23123);
    glVertex3f(31.90241, 8, -21.23123);
    glVertex3f(37.89843, 8, -20.05809);
    glVertex3f(37.89843, 11, -20.05809);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(37.89843, 11, -20.05809);
    glVertex3f(37.89843, 8, -20.05809);
    glVertex3f(44.02479, 8, -17.23322);
    glVertex3f(44.02479, 11, -17.23322);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(44.02479, 11, -17.23322);
    glVertex3f(44.02479, 8, -17.23322);
    glVertex3f(42.98201, 8, -14.19242);
    glVertex3f(42.98201, 11, -14.19242);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(42.98201, 11, -14.19242);
    glVertex3f(42.98201, 8, -14.19242);
    glVertex3f(37.11634, 8, -16.14765);
    glVertex3f(37.11634, 11, -16.14765);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(37.11634, 11, -16.14765);
    glVertex3f(37.11634, 8, -16.14765);
    glVertex3f(31.12032, 8, -16.79939);
    glVertex3f(31.12032, 11, -16.79939);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(31.12032, 11, -16.79939);
    glVertex3f(31.12032, 8, -16.79939);
    glVertex3f(26.16708, 8, -16.14765);
    glVertex3f(26.16708, 11, -16.14765);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(26.16708, 11, -16.14765);
    glVertex3f(26.16708, 8, -16.14765);
    glVertex3f(25.64569, 8, -20.57949);
    glVertex3f(25.64569, 11, -20.57949);
    glEnd();


    //atap ventilasi 5
    glBegin(GL_POLYGON);
    glColor3ub(3, 136, 252);
    glVertex3f(25.64569, 11, -20.57949);
    glVertex3f(31.90241, 11, -21.23123);
    glVertex3f(37.89843, 11, -20.05809);
    glVertex3f(44.02479, 11, -17.23322);
    glVertex3f(42.98201, 11, -14.19242);
    glVertex3f(37.11634, 11, -16.14765);
    glVertex3f(31.12032, 11, -16.79939);
    glVertex3f(26.16708, 11, -16.14765);
    glVertex3f(25.64569, 11, -20.57949);
    glEnd();


    //ventilasi 6
    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(24.97748, 11, -2.62437);
    glVertex3f(24.97748, 8, -2.62437);
    glVertex3f(30.07781, 8, -2.17434);
    glVertex3f(30.07781, 11, -2.17434);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(30.07781, 11, -2.17434);
    glVertex3f(30.07781, 8, -2.17434);
    glVertex3f(35.17814, 8, -2.02433);
    glVertex3f(35.17814, 11, -2.02433);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(35.17814, 11, -2.02433);
    glVertex3f(35.17814, 8, -2.02433);
    glVertex3f(43.7287, 8, -4.87452);
    glVertex3f(43.7287, 11, -4.87452);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(43.7287, 11, -4.87452);
    glVertex3f(43.7287, 8, -4.87452);
    glVertex3f(44.62875, 8, -0.17415);
    glVertex3f(44.62875, 11, -0.17415);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(44.62875, 11, -0.17415);
    glVertex3f(44.62875, 8, -0.17415);
    glVertex3f(39.52842, 8, 1.37602);
    glVertex3f(39.52842, 11, 1.37602);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(39.52842, 11, 1.37602);
    glVertex3f(39.52842, 8, 1.37602);
    glVertex3f(35.02813, 8, 1.82605);
    glVertex3f(35.02813, 11, 1.82605);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(35.02813, 11, 1.82605);
    glVertex3f(35.02813, 8, 1.82605);
    glVertex3f(29.77779, 8, 1.82605);
    glVertex3f(29.77779, 11, 1.82605);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(29.77779, 11, 1.82605);
    glVertex3f(29.77779, 8, 1.82605);
    glVertex3f(24.67746, 8, 0.77598);
    glVertex3f(24.67746, 11, 0.77598);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 136, 252);
    glVertex3f(24.67746, 11, 0.77598);
    glVertex3f(24.67746, 8, 0.77598);
    glVertex3f(24.97748, 8, -2.62437);
    glVertex3f(24.97748, 11, -2.62437);
    glEnd();

    //attap ventilasi 6
    glBegin(GL_POLYGON);
    glColor3ub(3, 136, 252);
    glVertex3f(24.97748, 11, -2.62437);
    glVertex3f(30.07781, 11, -2.17434);
    glVertex3f(35.17814, 11, -2.02433);
    glVertex3f(43.7287, 11, -4.87452);
    glVertex3f(44.62875, 11, -0.17415);
    glVertex3f(39.52842, 11, 1.37602);
    glVertex3f(35.02813, 11, 1.82605);
    glVertex3f(29.77779, 11, 1.82605);
    glVertex3f(24.67746, 11, 0.77598);
    glVertex3f(24.97748, 11, -2.62437);
    glEnd();


    //sekatt
    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-62, -8, -28);
    glVertex3f(-62, 5.3, -29);
    glVertex3f(-62, 5.3, 14);
    glVertex3f(-62, -8, 14);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-25, -8, -27);
    glVertex3f(-25, 5.3, -27);
    glVertex3f(-25, 5.3, 14);
    glVertex3f(-25, -8, 14);
    glEnd();
    glBegin(GL_QUADS);//pintu
    glColor3ub(112, 66, 6);
    glVertex3f(-25.1, -8, -24);
    glVertex3f(-25.1, 0, -24);
    glVertex3f(-25.1, 0, -18);
    glVertex3f(-25.1, -8, -18);
    glEnd();
    glBegin(GL_LINE_LOOP);//pintu
    glColor3ub(235, 154, 49);
    glVertex3f(-25.1, -8, -24.1);
    glVertex3f(-25.1, 0, -24.1);
    glVertex3f(-25.1, 0, -18.1);
    glVertex3f(-25.1, -8, -18.1);
    glEnd();
    //sekatt
    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(-25, -8, -8);
    glVertex3f(-25, 5.3, -8);
    glVertex3f(20, 5.3, -8);
    glVertex3f(20, -8, -8);
    glEnd();
    //sekatt
    glBegin(GL_QUADS);//pintu
    glColor3ub(112, 66, 6);
    glVertex3f(-18, -8, -8);
    glVertex3f(-18, 0, -8);
    glVertex3f(-12, 0, -8);
    glVertex3f(-12, -8, -8);
    glEnd();
    glBegin(GL_LINE_LOOP);//pintu
    glColor3ub(235, 154, 49);
    glVertex3f(-18, -8, -8);
    glVertex3f(-18, 0, -8);
    glVertex3f(-12, 0, -8);
    glVertex3f(-12, -8, -8);
    glEnd();


    //sekatt
    glBegin(GL_QUADS);
    glColor3ub(207, 226, 230);
    glVertex3f(20, -8, -26);
    glVertex3f(20, 5.3, -26);
    glVertex3f(20, 5.3, 12);
    glVertex3f(20, -8, 12);
    glEnd();

    glBegin(GL_QUADS); //kasurrr
    glColor3ub(240, 139, 139);
    glVertex3f(-55, -7, -15);
    glVertex3f(-38, -7, -15);
    glVertex3f(-38, -7, 10);
    glVertex3f(-55, -7, 10);
    glEnd();
    glBegin(GL_QUADS); //kasurrr
    glColor3ub(240, 139, 139);
    glVertex3f(-55, -7, -15);
    glVertex3f(-55, -8, -15);
    glVertex3f(-55, -8, 10);
    glVertex3f(-55, -7, 10);
    glEnd();
    glBegin(GL_QUADS); //kasurrr
    glColor3ub(240, 139, 139);
    glVertex3f(-38, -7, -15);
    glVertex3f(-38, -8, -15);
    glVertex3f(-38, -8, 10);
    glVertex3f(-38, -7, 10);
    glEnd();
    glBegin(GL_QUADS); //kasurrr
    glColor3ub(240, 139, 139);
    glVertex3f(-55, -7, 10);
    glVertex3f(-55, -8, 10);
    glVertex3f(-38, -8, 10);
    glVertex3f(-38, -7, 10);
    glEnd();
    glBegin(GL_QUADS); //kasurrr
    glColor3ub(240, 139, 139);
    glVertex3f(-55, -7, -15);
    glVertex3f(-55, -8, -15);
    glVertex3f(-38, -8, -15);
    glVertex3f(-38, -7, -15);
    glEnd();
    glBegin(GL_QUADS); //kasurrr
    glColor3ub(107, 105, 105);
    glVertex3f(-55, 0, 10);
    glVertex3f(-55, -8, 10);
    glVertex3f(-38, -8, 10);
    glVertex3f(-38, 0, 10);
    glEnd();
    glBegin(GL_QUADS); //bantalll
    glColor3ub(255, 0, 0);
    glVertex3f(-52, -7, 8);
    glVertex3f(-52, -7, 4);
    glVertex3f(-48, -7, 4);
    glVertex3f(-48, -7, 8);
    glEnd();
    glBegin(GL_QUADS); //bantalll
    glColor3ub(255, 0, 0);
    glVertex3f(-46, -7, 8);
    glVertex3f(-46, -7, 4);
    glVertex3f(-42, -7, 4);
    glVertex3f(-42, -7, 8);
    glEnd();
    glBegin(GL_QUADS); //babi guling
    glColor3ub(255, 0, 0);
    glVertex3f(-48, -7, -10);
    glVertex3f(-48, -7, 2);
    glVertex3f(-46, -7, 2);
    glVertex3f(-46, -7, -10);
    glEnd();

    glBegin(GL_QUADS); //kursi
    glColor3ub(0, 255, 0);
    glVertex3f(-54, -5, -18);
    glVertex3f(-40, -5, -18);
    glVertex3f(-40, -5, -22);
    glVertex3f(-54, -5, -22);
    glEnd();
    glBegin(GL_QUADS); //kursi
    glColor3ub(245, 184, 100);
    glVertex3f(-54, 0, -22);
    glVertex3f(-40, 0, -22);
    glVertex3f(-40, -8, -22);
    glVertex3f(-54, -8, -22);
    glEnd();
    glBegin(GL_QUADS); //kursi
    glColor3ub(245, 184, 100);
    glVertex3f(-54, -5, -18);
    glVertex3f(-40, -5, -18);
    glVertex3f(-40, -8, -18);
    glVertex3f(-54, -8, -18);
    glEnd();


    /// /////////////

    glBegin(GL_QUADS); //lemariiii cok
    glColor3ub(199, 188, 173);
    glVertex3f(-34, -8, -15);
    glVertex3f(-28, -8, -15);
    glVertex3f(-28, -8, 10);
    glVertex3f(-34, -8, 10);
    glEnd();
    glBegin(GL_QUADS); //lemariiii cok
    glColor3ub(199, 188, 173);
    glVertex3f(-34, 6, -15);
    glVertex3f(-28, 6, -15);
    glVertex3f(-28, 6, 10);
    glVertex3f(-34, 6, 10);
    glEnd();
    glBegin(GL_QUADS); //lemariiii cok
    glColor3ub(199, 188, 173);
    glVertex3f(-34, -8, -15);
    glVertex3f(-34, 6, -15);
    glVertex3f(-34, 6, 10);
    glVertex3f(-34, -8, 10);
    glEnd();
    glBegin(GL_QUADS); //lemariiii cok pintuuuuuu
    glColor3ub(112, 66, 6);
    glVertex3f(-34.5, -8, -5);
    glVertex3f(-34.5, 6, -5);
    glVertex3f(-34.5, 6, 0);
    glVertex3f(-34.5, -8, 0);
    glEnd();
    glBegin(GL_LINE_LOOP); //lemariiii cok pintuuuuuu
    glColor3ub(235, 154, 49);
    glVertex3f(-34.5, -8, -5.1);
    glVertex3f(-34.5, 6, -5.1);
    glVertex3f(-34.5, 6, 0.1);
    glVertex3f(-34.5, -8, 0.1);
    glEnd();
    glBegin(GL_QUADS); //lemariiii cok
    glColor3ub(199, 188, 173);
    glVertex3f(-28, -8, -15);
    glVertex3f(-28, 6, -15);
    glVertex3f(-28, 6, 10);
    glVertex3f(-28, -8, 10);
    glEnd();
    glBegin(GL_QUADS); //lemariiii cok
    glColor3ub(199, 188, 173);
    glVertex3f(-34, 6, -15);
    glVertex3f(-28, 6, -15);
    glVertex3f(-28, -10, -15);
    glVertex3f(-34, -10, -15);
    glEnd();
    glBegin(GL_QUADS); //lemariiii cok
    glColor3ub(199, 188, 173);
    glVertex3f(-34, 6, 10);
    glVertex3f(-28, 6, 10);
    glVertex3f(-28, -8, 10);
    glVertex3f(-34, -8, 10);
    glEnd();

    ///
        //karpet
    glBegin(GL_QUADS);
    glColor3ub(201, 201, 201);
    glVertex3f(-20, -8, -10);
    glVertex3f(15, -8, -10);
    glVertex3f(15, -8, -25);
    glVertex3f(-20, -8, -25);
    glEnd();
    glBegin(GL_QUADS); //meja 1
    glColor3ub(0, 0, 0);
    glVertex3f(-15, -4.9, -13);
    glVertex3f(-5, -4.9, -13);
    glVertex3f(-5, -4.9, -22);
    glVertex3f(-15, -4.9, -22);
    glEnd();
    glBegin(GL_QUADS); //meja 1 dobel
    glColor3ub(0, 0, 0);
    glVertex3f(-15, -4.8, -13);
    glVertex3f(-5, -4.8, -13);
    glVertex3f(-5, -4.8, -22);
    glVertex3f(-15, -4.8, -22);
    glEnd();
    glBegin(GL_QUADS); //meja 1 dobel
    glColor3ub(0, 0, 0);
    glVertex3f(-15, -4.7, -13);
    glVertex3f(-5, -4.7, -13);
    glVertex3f(-5, -4.7, -22);
    glVertex3f(-15, -4.7, -22);
    glEnd();
    glBegin(GL_QUADS); //meja 1 kaki X
    glColor3ub(252, 214, 162);
    glVertex3f(-13, -5.1, -15);
    glVertex3f(-7, -5.1, -15);
    glVertex3f(-7, -8, -20);
    glVertex3f(-13, -8, -20);
    glEnd();
    glBegin(GL_QUADS); //meja 1 kaki X
    glColor3ub(252, 214, 162);
    glVertex3f(-13, -5.1, -20);
    glVertex3f(-7, -5.1, -20);
    glVertex3f(-7, -8, -15);
    glVertex3f(-13, -8, -15);
    glEnd();

    glBegin(GL_QUADS); //meja 2
    glColor3ub(0, 0, 0);
    glVertex3f(0, -4.9, -13);
    glVertex3f(10, -4.9, -13);
    glVertex3f(10, -4.9, -22);
    glVertex3f(0, -4.9, -22);
    glEnd();
    glBegin(GL_QUADS); //meja 2 dobel
    glColor3ub(0, 0, 0);
    glVertex3f(0, -4.8, -13);
    glVertex3f(10, -4.8, -13);
    glVertex3f(10, -4.8, -22);
    glVertex3f(0, -4.8, -22);
    glEnd();
    glBegin(GL_QUADS); //meja 2 dobel
    glColor3ub(0, 0, 0);
    glVertex3f(0, -4.7, -13);
    glVertex3f(10, -4.7, -13);
    glVertex3f(10, -4.7, -22);
    glVertex3f(0, -4.7, -22);
    glEnd();


    glBegin(GL_QUADS); //meja 2 kaki X
    glColor3ub(252, 214, 162);
    glVertex3f(2, -5.1, -15);
    glVertex3f(8, -5.1, -15);
    glVertex3f(8, -8, -20);
    glVertex3f(2, -8, -20);
    glEnd();
    glBegin(GL_QUADS); //meja 2 kaki X
    glColor3ub(252, 214, 162);
    glVertex3f(2, -5.1, -20);
    glVertex3f(8, -5.1, -20);
    glVertex3f(8, -8, -15);
    glVertex3f(2, -8, -15);
    glEnd();

    ///
    //kamar
    glBegin(GL_QUADS);
    glColor3ub(252, 214, 162);
    glVertex3f(-15, -6, 10);
    glVertex3f(15, -6, 10);
    glVertex3f(15, -6, -5);
    glVertex3f(-15, -6, -5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 214, 162);
    glVertex3f(-15, -6, -5);
    glVertex3f(15, -6, -5);
    glVertex3f(15, -8, -5);
    glVertex3f(-15, -8, -5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(252, 214, 162);
    glVertex3f(-15, -6, 10);
    glVertex3f(15, -6, 10);
    glVertex3f(15, -8, 10);
    glVertex3f(-15, -8, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(252, 214, 162);
    glVertex3f(15, -6, 10);
    glVertex3f(15, -6, -5);
    glVertex3f(15, -8, -5);
    glVertex3f(15, -8, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(252, 214, 162);
    glVertex3f(-15, -6, 10);
    glVertex3f(-15, -6, -5);
    glVertex3f(-15, -8, -5);
    glVertex3f(-15, -8, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(252, 0, 0);//bantalll
    glVertex3f(9, -6, 5);
    glVertex3f(12, -6, 5);
    glVertex3f(12, -6, 0);
    glVertex3f(9, -6, 0);
    glEnd();



    //jalan2
    glBegin(GL_QUADS);
    glColor3ub(97, 93, 93);
    glVertex3f(56.84686, -7, 16.41662);
    glVertex3f(62.49695, -7, 18.34306);
    glVertex3f(-120.46455, -7, 95.83053);
    glVertex3f(-120.55358, -7, 89.50588);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(97, 93, 93);
    glVertex3f(56.84686, -7, 16.41662);
    glVertex3f(60.49695, -7, 18.34306);
    glVertex3f(80.32517, -7, 11.97099);
    glVertex3f(76.76183, -7, 9.787);
    glEnd();
    glBegin(GL_QUADS); //jalan loby
    glColor3ub(97, 93, 93);
    glVertex3f(60.20956, -7, 15.53432);
    glVertex3f(56.84686, -7, 16.41662);
    glVertex3f(48.79803, -7 , 15.26211);
    glVertex3f(52.60572, -7, 10.98886);
    glEnd();
    glBegin(GL_QUADS); //jalan loby
    glColor3ub(97, 93, 93);
    glVertex3f(48.79803, -7, 15.26211);
    glVertex3f(52.60572, -7, 10.98886);
    glVertex3f(-15, -7, 15);
    glVertex3f(-15.00318, -7, 17.05751);
    glEnd();
    glBegin(GL_QUADS); //jalan loby menuju ke luar
    glColor3ub(97, 93, 93);
    glVertex3f(-15.00318, -7, 17.05751);
    glVertex3f(-17.8724, -7 , 17.09229);
    glVertex3f(-14.35236, -7, 45.2682);
    glVertex3f(-11.7766, -7, 44.67909);
    glEnd();
    glBegin(GL_QUADS); //jalan loby menuju ke parkiran
    glColor3ub(97, 93, 93);
    glVertex3f(-15.00318, -7, 17.05751);
    glVertex3f(-14.69331, -7, 14.48718);
    glVertex3f(-110.26885, -7, 19.95594);
    glVertex3f(-110.59834, -7, 14.26674);
    glEnd();

    glBegin(GL_QUADS);// parkiran
    glColor3ub(97, 93, 93);
    glVertex3f(-110.26885, -7, 14.95594);
    glVertex3f(-140.59834, -7, 14.26674);
    glVertex3f(-140, -7, -30);
    glVertex3f(-110, -7, -30);
    glEnd();
    glBegin(GL_QUADS);// dr parkiran keluar
    glColor3ub(97, 93, 93);
    glVertex3f(-110.26885, -7, -40.95594);
    glVertex3f(-115.59834, -7, -45.95594);
    glVertex3f(-116.54809, -7, 90.61381);
    glVertex3f(-110.9398, -7, 90.61381);
    glEnd();
    glBegin(GL_QUADS);//jalan kekanan
    glColor3ub(97, 93, 93);
    glVertex3f(103.08636, -7, -1.42976);
    glVertex3f(106.06774, -7 ,2.33619);
    glVertex3f(80.32517, -7, 11.97099);
    glVertex3f(76.76183, -7, 9.787);
    glEnd();
    glBegin(GL_QUADS);// jalan belakang
    glColor3ub(97, 93, 93);
    glVertex3f(-110.26885, -7, -40.95594);
    glVertex3f(-115.59834, -7, -45.95594);
    glVertex3f(19.77384, -7, -33.71571);
    glVertex3f(19.37292, -7, -30.88451);
    glEnd();
    glBegin(GL_QUADS);// jalan belakang
    glColor3ub(97, 93, 93);
    glVertex3f(19.77384, -7, -33.71571);
    glVertex3f(19.37292, -7, -30.88451);
    glVertex3f(90.29253, -7, -23.01924);
    glVertex3f(93.12652, -7, -18.56582);
    glEnd();
    glBegin(GL_POLYGON);// jalan belakang
    glColor3ub(97, 93, 93);
    glVertex3f(90.29253, -7, -23.01924);
    glVertex3f(93.12652, -7, -18.56582);
    glVertex3f(100.72781, -7, -12.93181);
    glVertex3f(103.06276, -7, -8.3731);
    glVertex3f(103.08636, -7, -1.42976);
    glVertex3f(105.28653, -7, 2.74572);
    glVertex3f(114.95989, -7, -1.813);
    glVertex3f(119.40742, -7, -5.92696);
    glVertex3f(123.18782, -7, -11.81993);
    glVertex3f(117.7396, -7, -15.82271);
    glVertex3f(113.9592, -7, -17.82409);
    glVertex3f(104.95296, -7, -22.04924);
    glVertex3f(97.83692, -7, -22.93875);

    glEnd();


    //BOLA
    glTranslated(-73, 1.5, -5);
    glColor3ub(17, 160, 191);
    glutSolidSphere(10, 500, 100);
    glEnd();
    //BOLA kanan
    glTranslated(137, 1.1, -1.2);
    glColor3ub(17, 160, 191);
    glutSolidSphere(10, 500, 100);
    glEnd();









    glPopMatrix();
    glutSwapBuffers();
}

void idle() {
    if (!mouseDown) {
        xrot += 0.3f;
        yrot += 0.4f;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        zmov += 3.0;
        break;
    case 'd':
    case 'D':
        xmov += 3.0;
        break;
    case 's':
    case 'S':
        zmov -= 3.0;
        break;
    case 'a':
    case 'A':
        xmov -= 3.0;
        break;
    case '7':
        ymov += 3.0;
        break;
    case '9':
        ymov -= 3.0;
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -10.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
