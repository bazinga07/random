
//5b mapper

import java.io.IOException;
import java.util.StringTokenizer;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class WordMapper extends  Mapper<LongWritable,Text,Text,IntWritable>
{ 
	//private final static IntWritable one=;
	private Text word=new Text();
	
	public void map(LongWritable key, Text value,Context context) throws IOException,InterruptedException
	{
		String line = value.toString();
		StringTokenizer t=new StringTokenizer(line);
		while(t.hasMoreTokens())
		{
			word.set(t.nextToken(" "));
			context.write(word,new IntWritable(1));
			
		}
	}
}
