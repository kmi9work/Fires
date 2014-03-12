using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;


namespace Fire_forecast
{
    public partial class Dannie : Form
    {
        List<Rules> rules = new List<Rules>();
        List<Terms_list> terms = new List<Terms_list>();
        List<Fires_list> fires = new List<Fires_list>();
        List<Elements> elements = new List<Elements>();

        int chislo_strok;
        int chislo_factorov;
        int bi;//для какого то присваивания
        int koll;//чтобы определить в списке элементов, где начинается слудующий слой
        string soedenitel;
        double sup;
        int f1, f2, f3, f4, f5;

        void Vivod()
        {   int chislo_pravil;
            dg_pravila.Visible = true;
            dg_pravila.ColumnCount = 4;
            dg_pravila.Columns[0].Width = 50;
            dg_pravila.Columns[1].Width = 500;
            dg_pravila.Columns[2].Width = 100;
            dg_pravila.Columns[3].Width = 100;
            dg_pravila.Columns[0].HeaderText = "№";
            dg_pravila.Columns[1].HeaderText = "Если...";
            dg_pravila.Columns[2].HeaderText = "То...";
            dg_pravila.Columns[3].HeaderText = "Частота,%";

            chislo_pravil = rules.Count;

            if (chislo_pravil > 0)
                dg_pravila.RowCount = chislo_pravil;

            //rules.Sort();
            //MessageBox.Show(Convert.ToString(elements.Count));

            for (int i = 0; i < chislo_pravil; i++)
            {
                dg_pravila.Rows[i].Cells[0].Value = i + 1;
                dg_pravila.Rows[i].Cells[1].Value = rules[i].name;
                dg_pravila.Rows[i].Cells[2].Value = rules[i].fire_name;
                dg_pravila.Rows[i].Cells[3].Value = Math.Round(rules[i].sup, 2);//*100%   
                
            }
        }

        public Dannie()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Stream str_tovari = null;
            string directory = AppDomain.CurrentDomain.BaseDirectory;

   //-----------Загрузка из файла "Правила"------------------------------
   //--------------------------------------------------------------------
            openFileDialog1.FileName = directory + "pravila.csv";
            str_tovari = openFileDialog1.OpenFile();
            StreamReader myread_tovari = new StreamReader(str_tovari);
            string[] tovari;
            string[] tovari_1_stroka;
            int num_tovari = 0;
            int num_tovari_columns = 0;
            try
            {
                string[] tovari_1 = myread_tovari.ReadToEnd().Split('\n');
                num_tovari = tovari_1.Count();
                dg_dannie.RowCount = num_tovari;


                tovari_1_stroka = tovari_1[0].Split(';');
                num_tovari_columns = tovari_1_stroka.Count();
                dg_dannie.ColumnCount = num_tovari_columns;

                for (int i = 0; i < num_tovari; i++)
                {
                    tovari = tovari_1[i].Split(';');
                    for (int j = 0; j < dg_dannie.ColumnCount; j++)
                    {
                        try
                        {
                            dg_dannie.Rows[i].Cells[j].Value = tovari[j];
                        }
                        catch { }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                myread_tovari.Close();
            }
    //-----------/Загрузка из файла "Правила"------------------------------
    //---------------------------------------------------------------------
        }


        //------------------------Кнопка работы алгоритма--------------------------------------
        //-------------------------------------------------------------------------------------
        private void b_algoritm_apriori_Click(object sender, EventArgs e)
        {

            chislo_strok = 0;
            chislo_factorov = 0;

            dg_pravila.Rows.Clear();
            dg_fires_1.Rows.Clear();
            dg_fires_2.Rows.Clear();
            dg_fires_3.Rows.Clear();
            dg_fires_4.Rows.Clear();
            dg_fires_5.Rows.Clear();
            rules.Clear();
            terms.Clear();
            elements.Clear();
            fires.Clear();

            chislo_strok = dg_dannie.RowCount-1;
            chislo_factorov = dg_dannie.ColumnCount;

            //MessageBox.Show(Convert.ToString(chislo_strok));
            
            bool ogranichitel;
            bool ogranichitel_1;
            bool ogranichitel_2;
            bool abc;

            double supp_min = Convert.ToDouble(tb_supp_1.Text);
            double urovni_min = Convert.ToDouble(num_urovni_min.Text);
            double urovni_max = Convert.ToDouble(num_urovni_max.Text);
            
            double supp;
            double supp_1;
            double supp_2;



            //---Заполнение общего списка термов-----
            //-----------------------------------------
            for (int i = 1; i < chislo_strok; i++)
            {
                for (int j = 1; j < chislo_factorov-1; j++)
                {
                    abc = false;
                    for (int k = 0; k < terms.Count; k++)
                    {
                        if (terms[k].name == Convert.ToString(dg_dannie.Rows[i].Cells[j].Value))
                            abc = true;
                    }

                    if (abc == false)
                        terms.Add(new Terms_list(Convert.ToString(dg_dannie.Rows[i].Cells[j].Value)));
                }
            }
            //---/Заполнение общего списка термов-----
            //----------------------------------------
            
                       
            razbit_fires();//Заполнение таблиц пожаров по термам     
            elements.Clear();//Очистка предварительных правил
            Formirovanie();//Формирование кандидатов
            Perevod_supp();//Разделим значение поддержки на число пожаров этого вида
            Dop_rules();//Расчет поддержки
            Vivod();//Вывод на экран
 
        }               
        



        //-----------Разбивка пожаров на несколько таблиц---------------------
        //-------------------------------------------------------------------
        void razbit_fires()
        {           
            for (int i = 1; i < chislo_strok; i++)
            {
                for (int j = 1; j < chislo_factorov - 1; j++)
                {
                    bool abc = false;
                    for (int k = 0; k < fires.Count; k++)
                    {
                        if (fires[k].name == Convert.ToString(dg_dannie.Rows[i].Cells[chislo_factorov - 1].Value))
                            abc = true;
                    }

                    if (abc == false)
                        fires.Add(new Fires_list(Convert.ToString(dg_dannie.Rows[i].Cells[chislo_factorov - 1].Value)));
                }
            }

            dg_fires_1.ColumnCount = chislo_factorov;
            dg_fires_2.ColumnCount = chislo_factorov;
            dg_fires_3.ColumnCount = chislo_factorov;
            dg_fires_4.ColumnCount = chislo_factorov;
            dg_fires_5.ColumnCount = chislo_factorov;

            dg_fires_1.Rows.Add();
            dg_fires_2.Rows.Add();
            dg_fires_3.Rows.Add();
            dg_fires_4.Rows.Add();
            dg_fires_5.Rows.Add();
            for (int i = 0; i < chislo_factorov; i++)
            {
                dg_fires_1.Rows[0].Cells[i].Value = dg_dannie.Rows[0].Cells[i].Value;
                dg_fires_2.Rows[0].Cells[i].Value = dg_dannie.Rows[0].Cells[i].Value;
                dg_fires_3.Rows[0].Cells[i].Value = dg_dannie.Rows[0].Cells[i].Value;
                dg_fires_4.Rows[0].Cells[i].Value = dg_dannie.Rows[0].Cells[i].Value;
                dg_fires_5.Rows[0].Cells[i].Value = dg_dannie.Rows[0].Cells[i].Value;
            }

            f1 = 1;
            f2 = 1;
            f3 = 1;
            f4 = 1;
            f5 = 1;
            for (int i = 1; i < chislo_strok; i++)
            {
                //1-й терм
                if (Convert.ToString(dg_dannie.Rows[i].Cells[chislo_factorov - 1].Value) == fires[0].name)
                {
                    dg_fires_1.Rows.Add();   
                    for (int j = 0; j < chislo_factorov; j++)
                    {                                             
                        dg_fires_1.Rows[f1].Cells[j].Value = dg_dannie.Rows[i].Cells[j].Value;
                        dg_fires_1.Rows[f1].Cells[0].Value = f1;
                    }
                    f1++;
                }
                //2-й терм
                if (Convert.ToString(dg_dannie.Rows[i].Cells[chislo_factorov - 1].Value) == fires[1].name)
                {
                    dg_fires_2.Rows.Add(); 
                    for (int j = 0; j < chislo_factorov; j++)
                    {                                               
                        dg_fires_2.Rows[f2].Cells[j].Value = dg_dannie.Rows[i].Cells[j].Value;
                        dg_fires_2.Rows[f2].Cells[0].Value = f2;
                    }
                    f2++;
                }
                //3-й терм
                if (Convert.ToString(dg_dannie.Rows[i].Cells[chislo_factorov - 1].Value) == fires[2].name)
                {
                    dg_fires_3.Rows.Add();
                    for (int j = 0; j < chislo_factorov; j++)
                    {                        
                        dg_fires_3.Rows[f3].Cells[j].Value = dg_dannie.Rows[i].Cells[j].Value;
                        dg_fires_3.Rows[f3].Cells[0].Value = f3;
                    }
                    f3++;
                }
                //4-й терм
                if (Convert.ToString(dg_dannie.Rows[i].Cells[chislo_factorov - 1].Value) == fires[3].name)
                {
                    dg_fires_4.Rows.Add();
                    for (int j = 0; j < chislo_factorov; j++)
                    {                        
                        dg_fires_4.Rows[f4].Cells[j].Value = dg_dannie.Rows[i].Cells[j].Value;
                        dg_fires_4.Rows[f4].Cells[0].Value = f4;
                    }
                    f4++;
                }
                //5-й терм
                if (Convert.ToString(dg_dannie.Rows[i].Cells[chislo_factorov - 1].Value) == fires[4].name)
                {
                    dg_fires_5.Rows.Add();
                    for (int j = 0; j < chislo_factorov; j++)
                    {                        
                        dg_fires_5.Rows[f5].Cells[j].Value = dg_dannie.Rows[i].Cells[j].Value;
                        dg_fires_5.Rows[f5].Cells[0].Value = f5;
                    }
                    f5++;
                }
            }
        }
        //-----------/Разбивка пожаров на несколько таблиц---------------------
        //---------------------------------------------------------------------

        //-----------------Формирование кандидатов-----------------------------------
        //----------------------------------------------------------------
        void Formirovanie()
        {
            int supp_min = Convert.ToInt32(tb_supp_1.Text);
            int urovni_min = Convert.ToInt32(num_urovni_min.Text);
            int urovni_max = Convert.ToInt32(num_urovni_max.Text);

            
            for (int num_urovnia = urovni_min; num_urovnia <= urovni_max; num_urovnia++)
            {
                for (int i1 = 0; i1 < terms.Count; i1++)//--1 уровень
                {
                    if (num_urovnia != 1)
                    {
                        for (int i2 = i1 + 1; i2 < terms.Count; i2++)//--2 уровень
                        {
                            if (num_urovnia != 2)
                            {
                                for (int i3 = i2 + 1; i3 < terms.Count; i3++)//--3 уровень                                    
                                {
                                    if (num_urovnia != 3)
                                    {
                                        for (int i4 = i3 + 1; i4 < terms.Count; i4++)//--4 уровень
                                        {
                                            if (num_urovnia != 4)
                                            {
                                                for (int i5 = i4 + 1; i5 < terms.Count; i5++)//--5 уровень
                                                {
                                                    soedenitel = terms[i1].name + " AND " + terms[i2].name + " AND " + terms[i3].name + " AND " + terms[i4].name + " AND " + terms[i5].name; ;
                                                    podshet_1(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, terms[i3].name, terms[i4].name, terms[i5].name);
                                                    podshet_2(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, terms[i3].name, terms[i4].name, terms[i5].name);
                                                    podshet_3(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, terms[i3].name, terms[i4].name, terms[i5].name);
                                                    podshet_4(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, terms[i3].name, terms[i4].name, terms[i5].name);
                                                    podshet_5(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, terms[i3].name, terms[i4].name, terms[i5].name);
                                                }//5
                                            }
                                            else//4
                                            {
                                                soedenitel = terms[i1].name + " AND " + terms[i2].name + " AND " + terms[i3].name + " AND " + terms[i4].name;
                                                podshet_1(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, terms[i3].name, terms[i4].name, "");
                                                podshet_2(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, terms[i3].name, terms[i4].name, "");
                                                podshet_3(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, terms[i3].name, terms[i4].name, "");
                                                podshet_4(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, terms[i3].name, terms[i4].name, "");
                                                podshet_5(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, terms[i3].name, terms[i4].name, "");
                                            }
                                        }//4                                        
                                    }
                                    else//3
                                    {
                                        soedenitel = terms[i1].name + " AND " + terms[i2].name + " AND " + terms[i3].name;
                                        podshet_1(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, terms[i3].name, "", "");
                                        podshet_2(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, terms[i3].name, "", "");
                                        podshet_3(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, terms[i3].name, "", "");
                                        podshet_4(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, terms[i3].name, "", "");
                                        podshet_5(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, terms[i3].name, "", "");
                                    }
                                }
                            }//2
                            else//2
                            {
                                soedenitel = terms[i1].name + " AND " + terms[i2].name;                                
                                podshet_1(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, "", "", "");
                                podshet_2(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, "", "", "");
                                podshet_3(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, "", "", "");
                                podshet_4(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, "", "", "");
                                podshet_5(soedenitel, num_urovnia, terms[i1].name, terms[i2].name, "", "", "");
                            }

                        }
                    }
                    else//1
                    {
                        soedenitel = terms[i1].name;                        
                        podshet_1(soedenitel, num_urovnia, terms[i1].name, "", "", "", "");
                        podshet_2(soedenitel, num_urovnia, terms[i1].name, "", "", "", "");
                        podshet_3(soedenitel, num_urovnia, terms[i1].name, "", "", "", "");
                        podshet_4(soedenitel, num_urovnia, terms[i1].name, "", "", "", "");
                        podshet_5(soedenitel, num_urovnia, terms[i1].name, "", "", "", "");
                    }
                }//1   
            }         
        }
        //-----------------------//Формирование кандидатов-----------------------------
        //------------------------------------------------------------------

     //----------------------------Подсчет поддержки правил------------------------
     //-------------------------------------------------------------------------------
        //--------1 терм----------------------
        void podshet_1(string soedenitel, int num, string i1, string i2, string i3, string i4, string i5)
        {            
            int b;
            bool falser;
            string[] massiv = new string[5];
            bool ogranichitel = false;
            massiv[0] = i1;
            massiv[1] = i2;
            massiv[2] = i3;
            massiv[3] = i4;
            massiv[4] = i5;

            int count = 0;
            for(int i=0;i<5;i++)
            {
                if(massiv[i] !="")
                    count++;
            }

            int sravnenie;

            for (int i = 1; i < f1; i++) //возьмем какую то строку
            {
                sravnenie = 0;

                for (int k = 0; k < count; k++)//для каждой переменной правила
                {
                    falser = true;
                    for (int j = 1; j < chislo_factorov - 1; j++)//посмотрим на все факторы
                    {
                        if (massiv[k] == Convert.ToString(dg_fires_1.Rows[i].Cells[j].Value))//если такой фактор есть в таблице
                            if (falser == true)
                            {                                   
                                sravnenie++;
                                falser = false;                                                
                            }
                    }
                }

                if (sravnenie == count)
                {
                    if (ogranichitel == false)//если впервый раз встретился кандидат
                    {
                        elements.Add(new Elements(soedenitel, 0, num, fires[0].name));//добавим его в список
                        ogranichitel = true;
                    }                    
                    b = elements.Count - 1;
                    elements[b].sup++;//увеличим его поддержку

                }
            }            
                //elements[b].sup = elements[b].sup / f1-1;
        }
        //--------/1 терм----------------------

        //--------2 терм----------------------
        void podshet_2(string soedenitel, int num, string i1, string i2, string i3, string i4, string i5)
        {
            int b;
            bool falser;
            string[] massiv = new string[5];
            bool ogranichitel = false;
            massiv[0] = i1;
            massiv[1] = i2;
            massiv[2] = i3;
            massiv[3] = i4;
            massiv[4] = i5;

            int count = 0;
            for (int i = 0; i < 5; i++)
            {
                if (massiv[i] != "")
                    count++;
            }

            int sravnenie;

            for (int i = 1; i < f2; i++) //возьмем какую то строку
            {
                sravnenie = 0;

                for (int k = 0; k < count; k++)//для каждой переменной правила
                {
                    falser = true;
                    for (int j = 1; j < chislo_factorov - 1; j++)//посмотрим на все факторы
                    {
                        if (massiv[k] == Convert.ToString(dg_fires_2.Rows[i].Cells[j].Value))//если такой фактор есть в таблице
                            if (falser == true)
                            {
                                sravnenie++;
                                falser = false;
                            }
                    }
                }

                if (sravnenie == count)
                {
                    if (ogranichitel == false)//если впервый раз встретился кандидат
                    {
                        elements.Add(new Elements(soedenitel, 0, num, fires[1].name));//добавим его в список
                        ogranichitel = true;
                    }
                    b = elements.Count - 1;
                    elements[b].sup++;//увеличим его поддержку

                }
            }
            //elements[b].sup = elements[b].sup / f1-1;
        }
        //--------/2 терм----------------------

        //--------3 терм----------------------
        void podshet_3(string soedenitel, int num, string i1, string i2, string i3, string i4, string i5)
        {
            int b;
            bool falser;
            string[] massiv = new string[5];
            bool ogranichitel = false;
            massiv[0] = i1;
            massiv[1] = i2;
            massiv[2] = i3;
            massiv[3] = i4;
            massiv[4] = i5;

            int count = 0;
            for (int i = 0; i < 5; i++)
            {
                if (massiv[i] != "")
                    count++;
            }

            int sravnenie;

            for (int i = 1; i < f3; i++) //возьмем какую то строку
            {
                sravnenie = 0;

                for (int k = 0; k < count; k++)//для каждой переменной правила
                {
                    falser = true;
                    for (int j = 1; j < chislo_factorov - 1; j++)//посмотрим на все факторы
                    {
                        if (massiv[k] == Convert.ToString(dg_fires_3.Rows[i].Cells[j].Value))//если такой фактор есть в таблице
                            if (falser == true)
                            {
                                sravnenie++;
                                falser = false;
                            }
                    }
                }

                if (sravnenie == count)
                {
                    if (ogranichitel == false)//если впервый раз встретился кандидат
                    {
                        elements.Add(new Elements(soedenitel, 0, num, fires[2].name));//добавим его в список
                        ogranichitel = true;
                    }
                    b = elements.Count - 1;
                    elements[b].sup++;//увеличим его поддержку

                }
            }
            //elements[b].sup = elements[b].sup / f1-1;
        }
        //--------/3 терм----------------------

        //--------4 терм----------------------
        void podshet_4(string soedenitel, int num, string i1, string i2, string i3, string i4, string i5)
        {
            int b;
            bool falser;
            string[] massiv = new string[5];
            bool ogranichitel = false;
            massiv[0] = i1;
            massiv[1] = i2;
            massiv[2] = i3;
            massiv[3] = i4;
            massiv[4] = i5;

            int count = 0;
            for (int i = 0; i < 5; i++)
            {
                if (massiv[i] != "")
                    count++;
            }

            int sravnenie;

            for (int i = 1; i < f4; i++) //возьмем какую то строку
            {
                sravnenie = 0;

                for (int k = 0; k < count; k++)//для каждой переменной правила
                {
                    falser = true;
                    for (int j = 1; j < chislo_factorov - 1; j++)//посмотрим на все факторы
                    {
                        if (massiv[k] == Convert.ToString(dg_fires_4.Rows[i].Cells[j].Value))//если такой фактор есть в таблице
                            if (falser == true)
                            {
                                sravnenie++;
                                falser = false;
                            }
                    }
                }

                if (sravnenie == count)
                {
                    if (ogranichitel == false)//если впервый раз встретился кандидат
                    {
                        elements.Add(new Elements(soedenitel, 0, num, fires[3].name));//добавим его в список
                        ogranichitel = true;
                    }
                    b = elements.Count - 1;
                    elements[b].sup++;//увеличим его поддержку

                }
            }
            //elements[b].sup = elements[b].sup / f1-1;
        }
        //--------/4 терм----------------------

        //--------5 терм----------------------
        void podshet_5(string soedenitel, int num, string i1, string i2, string i3, string i4, string i5)
        {
            int b;
            bool falser;
            string[] massiv = new string[5];
            bool ogranichitel = false;
            massiv[0] = i1;
            massiv[1] = i2;
            massiv[2] = i3;
            massiv[3] = i4;
            massiv[4] = i5;

            int count = 0;
            for (int i = 0; i < 5; i++)
            {
                if (massiv[i] != "")
                    count++;
            }

            int sravnenie;

            for (int i = 1; i < f5; i++) //возьмем какую то строку
            {
                sravnenie = 0;

                for (int k = 0; k < count; k++)//для каждой переменной правила
                {
                    falser = true;
                    for (int j = 1; j < chislo_factorov - 1; j++)//посмотрим на все факторы
                    {
                        if (massiv[k] == Convert.ToString(dg_fires_5.Rows[i].Cells[j].Value))//если такой фактор есть в таблице
                            if (falser == true)
                            {
                                sravnenie++;
                                falser = false;
                            }
                    }
                }

                if (sravnenie == count)
                {
                    if (ogranichitel == false)//если впервый раз встретился кандидат
                    {
                        elements.Add(new Elements(soedenitel, 0, num, fires[4].name));//добавим его в список
                        ogranichitel = true;
                    }
                    b = elements.Count - 1;
                    elements[b].sup++;//увеличим его поддержку

                }
            }
            //elements[b].sup = elements[b].sup / f1-1;
        }
        //--------/5 терм----------------------
        //--------------------------/Подсчет поддержки правил-----------------------
        //-------------------------------------------------------------------------

        //-------------Разделим значение поддержки на число пожаров этого вида--------------
        //----------------------------------------------------------------------------------
        void Perevod_supp()
        {
            for (int i = 0; i < elements.Count; i++)
            {
                if (elements[i].fire_name == fires[0].name)
                    elements[i].sup = elements[i].sup / (f1 - 1) * 100;
                if (elements[i].fire_name == fires[1].name)
                    elements[i].sup = elements[i].sup / (f2 - 1) * 100;
                if (elements[i].fire_name == fires[2].name)
                    elements[i].sup = elements[i].sup / (f3 - 1) * 100;
                if (elements[i].fire_name == fires[3].name)
                    elements[i].sup = elements[i].sup / (f4 - 1) * 100;
                if (elements[i].fire_name == fires[4].name)
                    elements[i].sup = elements[i].sup / (f5 - 1) * 100;
            }
        }
        //---------------------/Разделим значение поддержки на число пожаров этого вида-----
        //----------------------------------------------------------------------------------

        //-----------Определение списка правил с допустимой поддержкой----------
        //----------------------------------------------------------------------
        void Dop_rules()
        {
            double supp_min_1 = Convert.ToDouble(tb_supp_1.Text);
            double supp_min_2 = Convert.ToDouble(tb_supp_2.Text);
            double supp_min_3 = Convert.ToDouble(tb_supp_3.Text);
            double supp_min_4 = Convert.ToDouble(tb_supp_4.Text);
            double supp_min_5 = Convert.ToDouble(tb_supp_5.Text);

            for (int i = 0; i < elements.Count; i++)
            {   //1
                if (elements[i].layer == 1)
                {
                    if (elements[i].sup >= supp_min_1)
                        rules.Add(new Rules(elements[i].name, elements[i].sup, elements[i].layer, elements[i].fire_name));
                }
                //2
                if (elements[i].layer == 2)
                {
                    if (elements[i].sup >= supp_min_2)
                        rules.Add(new Rules(elements[i].name, elements[i].sup, elements[i].layer, elements[i].fire_name));
                }
                //3
                if (elements[i].layer == 3)
                {
                    if (elements[i].sup >= supp_min_3)
                        rules.Add(new Rules(elements[i].name, elements[i].sup, elements[i].layer, elements[i].fire_name));
                }
                //4
                if (elements[i].layer == 4)
                {
                    if (elements[i].sup >= supp_min_4)
                        rules.Add(new Rules(elements[i].name, elements[i].sup, elements[i].layer, elements[i].fire_name));
                }
                //5
                if (elements[i].layer == 5)
                {
                    if (elements[i].sup >= supp_min_5)
                        rules.Add(new Rules(elements[i].name, elements[i].sup, elements[i].layer, elements[i].fire_name));
                }
            }
        }

        private void tb_urovni_min_TextChanged(object sender, EventArgs e)
        {

        }
        //-----------/Определение списка правил с допустимой поддкржкой----------
        //----------------------------------------------------------------------
    }
}
